/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 03:50:11 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/08 04:35:13 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

static void			key_a(t_wolf_3d *w, int **world_map)
{
	if (world_map[(int)(w->player.pos.x - (w->player.dir.y * 8
					* w->fps.movespeed))][(int)w->player.pos.y] == 0)
		w->player.pos.x -= w->player.dir.y * w->fps.movespeed;
	if (world_map[(int)w->player.pos.x][(int)(w->player.pos.y +
				(w->player.dir.x * 8 * w->fps.movespeed))] == 0)
		w->player.pos.y += w->player.dir.x * w->fps.movespeed;
}

static void			key_d(t_wolf_3d *w, int **world_map)
{
	if (world_map[(int)(w->player.pos.x + (w->player.dir.y * 8
					* w->fps.movespeed))][(int)w->player.pos.y] == 0)
		w->player.pos.x += w->player.dir.y * w->fps.movespeed;
	if (world_map[(int)w->player.pos.x][(int)(w->player.pos.y -
				(w->player.dir.x * 8 * w->fps.movespeed))] == 0)
		w->player.pos.y -= w->player.dir.x * w->fps.movespeed;
}

static void			key_up(t_wolf_3d *w, int **world_map)
{
	if (world_map[(int)(w->player.pos.x + (w->player.dir.x * 8
					* w->fps.movespeed))][(int)w->player.pos.y] == 0)
		w->player.pos.x += w->player.dir.x * w->fps.movespeed;
	if (world_map[(int)w->player.pos.x][(int)(w->player.pos.y +
				(w->player.dir.y * 8 * w->fps.movespeed))] == 0)
		w->player.pos.y += w->player.dir.y * w->fps.movespeed;
}

static void			key_down(t_wolf_3d *w, int **world_map)
{
	if (world_map[(int)(w->player.pos.x - w->player.dir.x *
				8 * w->fps.movespeed)][(int)w->player.pos.y] == 0)
		w->player.pos.x -= w->player.dir.x * w->fps.movespeed;
	if (world_map[(int)w->player.pos.x][(int)(w->player.pos.y -
				w->player.dir.y * 8 * w->fps.movespeed)] == 0)
		w->player.pos.y -= w->player.dir.y * w->fps.movespeed;
}

void				key_down_input(t_wolf_3d *w,
		const Uint8 *keys, int **world_map)
{
	if (keys[SDL_SCANCODE_A])
		key_a(w, world_map);
	if (keys[SDL_SCANCODE_D])
		key_d(w, world_map);
	if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP])
		key_up(w, world_map);
	if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN])
		key_down(w, world_map);
	if (keys[SDL_SCANCODE_R])
	{
		SDL_WarpMouseInWindow(w->sdl.win, (WIDTH / 2), (HEIGHT / 2));
		init_perso(w);
	}
}
