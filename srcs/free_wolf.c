/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 01:41:22 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/12 14:40:27 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void		free_map(char **map, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void		free_map2(int **map, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void		free_surface(t_wolf_3d *w)
{
	SDL_FreeSurface(w->sdl.cur);
	SDL_FreeSurface(w->sdl.wall1);
	SDL_FreeSurface(w->sdl.wall2);
	SDL_FreeSurface(w->sdl.wall3);
	SDL_FreeSurface(w->sdl.wall4);
	SDL_FreeSurface(w->sdl.wall5);
	SDL_FreeSurface(w->sdl.wall6);
	SDL_FreeSurface(w->sdl.wall7);
	SDL_FreeSurface(w->sdl.wall8);
	SDL_FreeSurface(w->sdl.wall9);
	SDL_FreeSurface(w->sdl.wall10);
	SDL_FreeSurface(w->sdl.wall11);
	SDL_FreeSurface(w->sdl.wall12);
	SDL_FreeSurface(w->sdl.roof_texture1);
	SDL_FreeSurface(w->sdl.floor_texture1);
	SDL_FreeSurface(w->sdl.roof_texture2);
	SDL_FreeSurface(w->sdl.floor_texture2);
	SDL_FreeSurface(w->sdl.roof_texture3);
	SDL_FreeSurface(w->sdl.floor_texture3);
}

void		sdl_quit(t_wolf_3d *w)
{
	SDL_DestroyRenderer(w->sdl.renderer);
	SDL_DestroyWindow(w->sdl.win);
	free_map2(w->player.world_map, 24);
	free(w->data);
	free(w);
	TTF_Quit();
	SDL_Quit();
}
