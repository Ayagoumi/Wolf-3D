/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 03:45:01 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/11 17:07:46 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void			load_kp1(t_wolf_3d *w)
{
	w->sdl.new_text[0] = (unsigned int *)w->sdl.wall1->pixels;
	w->sdl.new_text[1] = (unsigned int *)w->sdl.wall2->pixels;
	w->sdl.new_text[2] = (unsigned int *)w->sdl.wall3->pixels;
	w->sdl.new_text[3] = (unsigned int *)w->sdl.wall4->pixels;
	w->sdl.wall_data_ceiling = (unsigned int *)w->sdl.roof_texture1->pixels;
	w->sdl.wall_data_floor = (unsigned int *)w->sdl.floor_texture1->pixels;
}

void			load_kp2(t_wolf_3d *w)
{
	w->sdl.new_text[0] = (unsigned int *)w->sdl.wall5->pixels;
	w->sdl.new_text[1] = (unsigned int *)w->sdl.wall6->pixels;
	w->sdl.new_text[2] = (unsigned int *)w->sdl.wall7->pixels;
	w->sdl.new_text[3] = (unsigned int *)w->sdl.wall8->pixels;
	w->sdl.wall_data_ceiling = (unsigned int *)w->sdl.roof_texture2->pixels;
	w->sdl.wall_data_floor = (unsigned int *)w->sdl.floor_texture2->pixels;
}

void			load_kp3(t_wolf_3d *w)
{
	w->sdl.new_text[0] = (unsigned int *)w->sdl.wall9->pixels;
	w->sdl.new_text[1] = (unsigned int *)w->sdl.wall10->pixels;
	w->sdl.new_text[2] = (unsigned int *)w->sdl.wall11->pixels;
	w->sdl.new_text[3] = (unsigned int *)w->sdl.wall12->pixels;
	w->sdl.wall_data_ceiling = (unsigned int *)w->sdl.roof_texture3->pixels;
	w->sdl.wall_data_floor = (unsigned int *)w->sdl.floor_texture3->pixels;
}
