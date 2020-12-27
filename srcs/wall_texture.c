/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 23:24:39 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/09 03:10:54 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void		wall_texture(t_wolf_3d *wolf, int x, int start, int end)
{
	int		color;

	if (wolf->ray.side == 1)
		wolf->wallx = wolf->player.pos.x + wolf->ray.perpwalldist
			* wolf->ray.raydir.x;
	else
		wolf->wallx = wolf->player.pos.y + wolf->ray.perpwalldist
			* wolf->ray.raydir.y;
	wolf->wallx -= floor(wolf->wallx);
	wolf->texx = (int)(wolf->wallx * (double)TEXT_W);
	if (wolf->ray.side == 0 && wolf->ray.raydir.x > 0)
		wolf->texx = TEXT_W - wolf->texx - 1;
	if (wolf->ray.side == 1 && wolf->ray.raydir.y < 0)
		wolf->texx = TEXT_W - wolf->texx - 1;
	while (++start < end)
	{
		wolf->texy = ((start - wolf->event.down_mouve) * 2 - HEIGHT +
				wolf->ray.lineheight) *
			(TEXT_H / 2) / wolf->ray.lineheight;
		color = wolf->sdl.new_text[wolf->wallnbr]
			[wolf->texy * TEXT_H + wolf->texx];
		wall_light_input(wolf, &color);
		if (start < HEIGHT && start >= 0)
			wolf->data[start * WIDTH + x] = color;
	}
}

void		init_clrf(t_wolf_3d *w)
{
	w->ray.ray0.x = w->player.dir.x - w->player.plane.x;
	w->ray.ray0.y = w->player.dir.y - w->player.plane.y;
	w->ray.ray1.x = w->player.dir.x + w->player.plane.x;
	w->ray.ray1.y = w->player.dir.y + w->player.plane.y;
}

void		calc_floor(t_wolf_3d *w, int y, int check)
{
	if (check == 1)
		w->p = -(y - HEIGHT / 2) + w->event.down_mouve;
	else
		w->p = (y - HEIGHT / 2) - w->event.down_mouve;
	w->posz = 0.5 * HEIGHT;
	w->rowdistance = w->posz / w->p;
	w->floorstepx = w->rowdistance * (w->ray.ray1.x - w->ray.ray0.x) / WIDTH;
	w->floorstepy = w->rowdistance * (w->ray.ray1.y - w->ray.ray0.y) / WIDTH;
	w->floorx = w->player.pos.x + w->rowdistance * w->ray.ray0.x;
	w->floory = w->player.pos.y + w->rowdistance * w->ray.ray0.y;
}

void		texture_cling(t_wolf_3d *w)
{
	int		y;
	int		x;
	int		color;

	init_clrf(w);
	y = -1;
	while (++y < (HEIGHT / 2) + w->event.down_mouve)
	{
		calc_floor(w, y, 1);
		x = -1;
		while (++x < WIDTH)
		{
			w->cellx = (int)(w->floorx);
			w->celly = (int)(w->floory);
			w->texx2 = (int)(TEXT_W * (w->floorx - w->cellx)) & (TEXT_W - 1);
			w->texy2 = (int)(TEXT_H * (w->floory - w->celly)) & (TEXT_H - 1);
			w->floorx += w->floorstepx;
			w->floory += w->floorstepy;
			color = w->sdl.wall_data_ceiling[TEXT_W * w->texx2 + w->texy2];
			light_input(w, &color);
			if (y < HEIGHT)
				w->data[WIDTH * y + x] = color;
		}
	}
}

void		texture_floor(t_wolf_3d *w)
{
	int		y;
	int		x;
	int		color;

	init_clrf(w);
	y = (HEIGHT / 2 + w->event.down_mouve) - 1;
	while (++y < HEIGHT)
	{
		calc_floor(w, y, 0);
		x = -1;
		while (++x < WIDTH)
		{
			w->cellx = (int)(w->floorx);
			w->celly = (int)(w->floory);
			w->texx2 = (int)(TEXT_W * (w->floorx - w->cellx)) & (TEXT_W - 1);
			w->texy2 = (int)(TEXT_H * (w->floory - w->celly)) & (TEXT_H - 1);
			w->floorx += w->floorstepx;
			w->floory += w->floorstepy;
			color = w->sdl.wall_data_floor[TEXT_W * w->texx2 + w->texy2];
			light_input(w, &color);
			if ((y) >= 0 && (y) < HEIGHT)
				w->data[WIDTH * y + x] = color;
		}
	}
}
