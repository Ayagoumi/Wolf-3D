/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:24:48 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/13 14:48:19 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void	update(t_wolf_3d *w)
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(),
		(w->fps.last_frame_time + w->fps.frame_target)))
		;
	w->fps.delta_time = (SDL_GetTicks() - w->fps.last_frame_time) / 1000.0f;
	w->fps.last_frame_time = SDL_GetTicks();
	w->fps.movespeed = 2 * w->fps.delta_time;
	w->fps.rotspeed = 2 * w->fps.delta_time;
}

void	render(t_wolf_3d *w)
{
	static int i;

	main_page(w, &i);
	SDL_RenderPresent(w->sdl.renderer);
}
