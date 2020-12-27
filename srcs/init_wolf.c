/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:13:22 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/16 04:01:29 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

/*
** check for the fisrt  0 spot
*/

void		player_start(t_wolf_3d *w)
{
	int				i;
	int				j;
	static int		second;

	i = MAP_NUM_COLS;
	while (--i >= 0)
	{
		j = MAP_NUM_ROWS;
		while (--j >= 0)
		{
			if (w->player.world_map[i][j] == 0 && second++)
			{
				w->player.pos.x = i + 0.35;
				w->player.pos.y = j + 0.35;
				return ;
			}
		}
	}
	if (second == 0 || second == 1)
	{
		show_error_map();
		free_map2(w->player.world_map, MAP_NUM_COLS);
		free(w);
		exit(0);
	}
}

void		init_perso(t_wolf_3d *w)
{
	player_start(w);
	SDL_WarpMouseInWindow(w->sdl.win, (WIDTH / 2), (HEIGHT / 2));
	w->data = malloc(sizeof(int) * (WIDTH * HEIGHT));
	w->sdl.font = TTF_OpenFont(LAZZY, 25);
	w->event.light1 = 0;
	w->event.light2 = 0;
	w->event.darken_value = 3.5;
	w->player.dir.x = -1;
	w->player.dir.y = 0;
	w->player.with = 20;
	w->player.height = 20;
	w->player.plane.x = 0;
	w->player.plane.y = 0.57;
	w->sdl.color.r = 255;
	w->sdl.color.g = 255;
	w->sdl.color.b = 102;
	w->dst.w = 100;
	w->dst.h = 100;
	w->dst.x = (WIDTH / 2) - (w->dst.w / 2);
	w->dst.y = (HEIGHT / 2) - (w->dst.h / 2);
}

void		load_font(t_wolf_3d *w)
{
	int			i;
	int			j;
	char		*fps_count;
	char		*fps_show;

	i = 0;
	j = 0;
	fps_count = ft_itoa(1 / w->fps.delta_time);
	fps_show = ft_strjoin("FPS: ", fps_count);
	w->sdl.font1 = TTF_RenderText_Solid(w->sdl.font, fps_show, w->sdl.color);
	w->sdl.msg = SDL_CreateTextureFromSurface(w->sdl.renderer, w->sdl.font1);
	SDL_QueryTexture(w->sdl.msg, NULL, NULL, &i, &j);
	w->sdl.dstrect.x = WIDTH - 130;
	w->sdl.dstrect.y = 8;
	w->sdl.dstrect.w = i;
	w->sdl.dstrect.h = j;
	SDL_RenderCopy(w->sdl.renderer, w->sdl.msg, NULL, &w->sdl.dstrect);
	SDL_FreeSurface(w->sdl.font1);
	SDL_DestroyTexture(w->sdl.msg);
	free(fps_count);
	free(fps_show);
	fps_count = NULL;
	fps_show = NULL;
}

void		load_img(t_wolf_3d *w)
{
	w->sdl.roof_texture1 = IMG_Load(SKY);
	w->sdl.floor_texture1 = IMG_Load(BARK);
	w->sdl.wall1 = IMG_Load(FRAME1);
	w->sdl.wall2 = IMG_Load(FRAME2);
	w->sdl.wall3 = IMG_Load(FRAME3);
	w->sdl.wall4 = IMG_Load(FRAME4);
	w->sdl.roof_texture2 = IMG_Load(SKY2);
	w->sdl.floor_texture2 = IMG_Load(MOLDSTONE);
	w->sdl.wall5 = IMG_Load(GREYSTONE);
	w->sdl.wall6 = IMG_Load(GOLD_CUP);
	w->sdl.wall7 = IMG_Load(FLAG);
	w->sdl.wall8 = IMG_Load(HITLERGREYSTONE);
	w->sdl.floor_texture3 = IMG_Load(BLUEFLOOR);
	w->sdl.roof_texture3 = IMG_Load(SKY3);
	w->sdl.wall9 = IMG_Load(BLUEDEVIL);
	w->sdl.wall10 = IMG_Load(CAGEWALL);
	w->sdl.wall11 = IMG_Load(BLUESTONE);
	w->sdl.wall12 = IMG_Load(BLUELINE);
	w->sdl.new_text = malloc(sizeof(unsigned int *) * 4);
	w->sdl.new_text[0] = (unsigned int *)w->sdl.wall1->pixels;
	w->sdl.new_text[1] = (unsigned int *)w->sdl.wall2->pixels;
	w->sdl.new_text[2] = (unsigned int *)w->sdl.wall3->pixels;
	w->sdl.new_text[3] = (unsigned int *)w->sdl.wall4->pixels;
	w->sdl.wall_data_ceiling = (unsigned int *)w->sdl.roof_texture1->pixels;
	w->sdl.wall_data_floor = (unsigned int *)w->sdl.floor_texture1->pixels;
}
