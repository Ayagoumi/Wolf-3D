/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:28:13 by ayagoumi          #+#    #+#             */
/*   Updated: 2020/12/12 20:15:27 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void		arrow_move_input(t_wolf_3d *w, const Uint8 *keystates)
{
	if (keystates[SDL_SCANCODE_LEFT])
		calculate_plane_dir_x(w, 30 * (3.14 * w->fps.rotspeed) / 180.0);
	if (keystates[SDL_SCANCODE_RIGHT])
		calculate_plane_dir_x(w, -30 * (3.14 * w->fps.rotspeed) / 180.0);
}

void		wall_light_input(t_wolf_3d *w, int *color)
{
	if (w->event.keystates[SDL_SCANCODE_K])
		w->event.light1 = 0;
	else if (w->event.keystates[SDL_SCANCODE_L])
		w->event.light1 = 1;
	if (w->event.light1)
	{
		darken_wall_color(w, color);
		if (w->event.keystates[SDL_SCANCODE_KP_PLUS])
			w->event.darken_value = 3.5;
		if (w->event.keystates[SDL_SCANCODE_KP_MINUS])
			w->event.darken_value = 0.9;
	}
}

void		light_input(t_wolf_3d *w, int *color)
{
	if (w->event.keystates[SDL_SCANCODE_K])
		w->event.light2 = 0;
	else if (w->event.keystates[SDL_SCANCODE_L])
		w->event.light2 = 1;
	if (w->event.light2)
	{
		darken_fall_color(w, color);
		if (w->event.keystates[SDL_SCANCODE_KP_PLUS])
			w->event.darken_value = 3.5;
		if (w->event.keystates[SDL_SCANCODE_KP_MINUS])
			w->event.darken_value = 0.9;
	}
}

void		process_input(t_wolf_3d *w, int **world_map)
{
	w->event.keystates = SDL_GetKeyboardState(NULL);
	track_mouse(w, &w->mousestates);
	SDL_PollEvent(&w->sdl.event);
	if (w->sdl.event.type == SDL_QUIT)
		w->game_running = 1;
	if (w->event.keystates[SDL_SCANCODE_ESCAPE])
		w->game_running = 1;
	arrow_move_input(w, w->event.keystates);
	key_down_input(w, w->event.keystates, world_map);
	mouse_motion_input(w, &w->mousestates);
	clear_data_tab(w->data);
}
