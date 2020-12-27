/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_miniMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 02:20:51 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/08 22:42:43 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

/*
**	hadi ba9i fiha tkhawr bzaaaf
**	lmochkil howa anana kancheckiw khir awal pixel mn lplyer rect
**	mais le dernier point dyal hadak lcube makanchekiwhch
**	ana mrdni hadchi  wach momkin tchouf lproblem fin kain?
*/

void		player_inmini(t_wolf_3d *w)
{
	double	x;
	double	y;

	x = w->player.pos.y;
	y = w->player.pos.x;
	SDL_SetRenderDrawColor(w->sdl.renderer, 255, 0, 0, 255);
	w->sdl.player = (SDL_Rect){
		x * MAP_SACLER * TILE_SIZE,
		y * MAP_SACLER * TILE_SIZE,
		20 * MAP_SACLER,
		20 * MAP_SACLER};
	SDL_RenderFillRect(w->sdl.renderer, &w->sdl.player);
}

void		mini_map(t_wolf_3d *w)
{
	int		i;
	int		j;
	int		color_map;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			color_map = w->player.world_map[i][j] != 0 ? 255 : 0;
			SDL_SetRenderDrawBlendMode(w->sdl.renderer, SDL_BLENDMODE_BLEND);
			SDL_SetRenderDrawColor(w->sdl.renderer,
					color_map, color_map, color_map, 255);
			w->sdl.map = (SDL_Rect){
				(int)(j * TILE_SIZE * MAP_SACLER),
				(int)(i * TILE_SIZE * MAP_SACLER),
				TILE_SIZE * MAP_SACLER,
				TILE_SIZE * MAP_SACLER};
			SDL_RenderFillRect(w->sdl.renderer, &w->sdl.map);
			j++;
		}
		i++;
	}
}

void		mini_player(t_wolf_3d *w)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			if (i == (int)w->player.pos.x && j == (int)w->player.pos.y)
				player_inmini(w);
			j++;
		}
		i++;
	}
}
