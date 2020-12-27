/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:23:04 by ayagoumi          #+#    #+#             */
/*   Updated: 2020/12/13 14:56:41 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void	index_page(t_wolf_3d *w, int *i)
{
	w->sdl.page = 0;
	if (*i <= 30)
	{
		w->sdl.index = IMG_Load(INDEX);
		w->sdl.index_tex = SDL_CreateTextureFromSurface(w->sdl.renderer,
				w->sdl.index);
		SDL_RenderCopy(w->sdl.renderer, w->sdl.index_tex, NULL, NULL);
		SDL_FreeSurface(w->sdl.index);
		(*i)++;
	}
}

void	index_page2(t_wolf_3d *w)
{
	w->sdl.page = 2;
	w->sdl.index = IMG_Load(INDEX2);
	w->sdl.index_tex = SDL_CreateTextureFromSurface(w->sdl.renderer,
			w->sdl.index);
	SDL_RenderCopy(w->sdl.renderer, w->sdl.index_tex, NULL, NULL);
	SDL_FreeSurface(w->sdl.index);
}

void	index_page3(t_wolf_3d *w, int *i)
{
	w->sdl.page = 3;
	w->sdl.index = IMG_Load(INDEX3);
	w->sdl.index_tex = SDL_CreateTextureFromSurface(w->sdl.renderer,
			w->sdl.index);
	SDL_RenderCopy(w->sdl.renderer, w->sdl.index_tex, NULL, NULL);
	SDL_FreeSurface(w->sdl.index);
	(*i)++;
}

void	start_index_page(t_wolf_3d *w, int *i)
{
	SDL_Rect	dst;

	dst.w = 100;
	dst.h = 100;
	dst.x = (WIDTH / 2) - (dst.w / 2);
	dst.y = (HEIGHT / 2) - (dst.h / 2);
	index_page2(w);
	if (w->sdl.event.type == SDL_MOUSEBUTTONDOWN &&\
		w->sdl.event.button.button == SDL_BUTTON_LEFT)
	{
		SDL_GetMouseState(&w->event.newmouse.x, &w->event.newmouse.y);
		if (((w->event.newmouse.x >= 344 && w->event.newmouse.y >= 638) &&\
			(w->event.newmouse.x <= 558 && w->event.newmouse.y <= 700)) &&\
			w->sdl.page == 2)
		{
			w->sdl.page = 3;
			w->sdl.index_i = 1;
		}
		else if (((w->event.newmouse.x >= 344 && w->event.newmouse.y >= 742) &&\
				(w->event.newmouse.x <= 558 && w->event.newmouse.y <= 806)) &&\
				w->sdl.page == 2)
			w->game_running = 1;
	}
	if (w->sdl.index_i)
		index_page3(w, i);
}

void	main_page(t_wolf_3d *w, int *i)
{
	if (w->sdl.page == 0)
		(*i <= 30) ? index_page(w, i) : (w->sdl.page = 2);
	else if (w->sdl.page == 2)
		start_index_page(w, i);
	else if (w->sdl.page == 3 || w->sdl.page == 4)
	{
		main_page_events(w);
		if (w->sdl.index_i_tex)
		{
			draw_map_3d(w);
			SDL_UpdateTexture(w->sdl.texture, NULL, w->data,\
					WIDTH * sizeof(int));
			SDL_RenderCopy(w->sdl.renderer, w->sdl.texture, NULL, NULL);
			SDL_RenderCopy(w->sdl.renderer, w->sdl.cur_tex, NULL, &w->dst);
			SDL_FreeSurface(w->sdl.cur);
			image_clear(w);
			mini_map(w);
			mini_player(w);
			load_font(w);
		}
	}
}
