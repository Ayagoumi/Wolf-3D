/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 05:14:13 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/13 14:52:37 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void		darken_wall_color(t_wolf_3d *w, int *color)
{
	unsigned char	*p;
	int				n;

	p = (unsigned char *)color;
	p[3] = 0;
	n = (w->ray.perpwalldist * w->event.darken_value);
	if (n == 0)
		n = 1;
	p[1] = p[1] / n;
	p[2] = p[2] / n;
	p[0] = p[0] / n;
}

void		darken_fall_color(t_wolf_3d *w, int *color)
{
	unsigned char	*p;
	int				n;

	p = (unsigned char *)color;
	p[3] = 0;
	n = (w->rowdistance * w->event.darken_value);
	if (n == 0)
		n = 1;
	p[1] = p[1] / n;
	p[2] = p[2] / n;
	p[0] = p[0] / n;
}

void		detect_start_end(t_wolf_3d *w)
{
	w->ray.lineheight = (int)(HEIGHT / w->ray.perpwalldist);
	if (w->ray.perpwalldist <= 0)
		w->ray.lineheight = WIDTH;
	w->ray.draw.start = (int)((-w->ray.lineheight / 2) + (HEIGHT / 2))
		+ w->event.up_mouve;
	if (w->ray.draw.start < 0)
		w->ray.draw.start = 0;
	w->ray.draw.end = (int)((w->ray.lineheight / 2) + (HEIGHT / 2))
		+ w->event.down_mouve;
	if (w->ray.draw.end >= HEIGHT)
		w->ray.draw.end = HEIGHT - 1;
}

void		init_calc(t_wolf_3d *w, int x)
{
	double	tmp1;
	double	tmp2;

	w->ray.camerax = 2 * x / (double)WIDTH - 1;
	w->ray.raydir.x = w->player.dir.x + w->player.plane.x * w->ray.camerax;
	w->ray.raydir.y = w->player.dir.y + w->player.plane.y * w->ray.camerax;
	tmp1 = (w->ray.raydir.x == 0) ? 1 : fabs(1 / w->ray.raydir.x);
	tmp2 = (w->ray.raydir.y == 0) ? 1 : fabs(1 / w->ray.raydir.y);
	w->ray.deltadist.x = (w->ray.raydir.y == 0) ? 0 : tmp1;
	w->ray.deltadist.y = (w->ray.raydir.x == 0) ? 0 : tmp2;
	w->ray.hit = 0;
	w->ray.map.x = (int)w->player.pos.x;
	w->ray.map.y = (int)w->player.pos.y;
}

void		draw_map_3d(t_wolf_3d *w)
{
	int x;

	x = 0;
	SDL_ShowCursor(0);
	texture_cling(w);
	texture_floor(w);
	while (x < WIDTH)
	{
		init_calc(w, x);
		step_taken(w);
		dda_algorithm(w);
		detect_start_end(w);
		wall_texture(w, x, w->ray.draw.start - 1, w->ray.draw.end);
		x++;
	}
	w->sdl.cur = IMG_Load(CUR);
	w->sdl.cur_tex = SDL_CreateTextureFromSurface(w->sdl.renderer,
			w->sdl.cur);
}
