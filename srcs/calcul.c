/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:07:30 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/09 03:02:04 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void		calculate_plane_dir_x(t_wolf_3d *w, double rotation_speed)
{
	float	cos_calc;
	float	sin_calc;

	cos_calc = cos(rotation_speed);
	sin_calc = sin(rotation_speed);
	w->olddirx = w->player.dir.x;
	w->player.dir.x = w->player.dir.x * cos_calc - w->player.dir.y * sin_calc;
	w->player.dir.y = w->olddirx * sin_calc + w->player.dir.y * cos_calc;
	w->oldplanex = w->player.plane.x;
	w->player.plane.x = w->player.plane.x * cos_calc
		- w->player.plane.y * sin_calc;
	w->player.plane.y = w->oldplanex * sin_calc
		+ w->player.plane.y * cos_calc;
}

void		step_taken(t_wolf_3d *w)
{
	if (w->ray.raydir.x < 0)
	{
		w->ray.step.x = -1;
		w->ray.sidedist.x = (w->player.pos.x - w->ray.map.x)
			* w->ray.deltadist.x;
	}
	else
	{
		w->ray.step.x = 1;
		w->ray.sidedist.x = (w->ray.map.x + 1.0 - w->player.pos.x)
			* w->ray.deltadist.x;
	}
	if (w->ray.raydir.y < 0)
	{
		w->ray.step.y = -1;
		w->ray.sidedist.y = (w->player.pos.y - w->ray.map.y)
			* w->ray.deltadist.y;
	}
	else
	{
		w->ray.step.y = 1;
		w->ray.sidedist.y = (w->ray.map.y + 1.0 - w->player.pos.y)
			* w->ray.deltadist.y;
	}
}

void		check_texture_x(t_wolf_3d *w)
{
	if (w->ray.raydir.x > 0)
		w->wallnbr = 0;
	else
		w->wallnbr = 1;
}

void		check_texture_y(t_wolf_3d *w)
{
	if (w->ray.raydir.y > 0)
		w->wallnbr = 2;
	else
		w->wallnbr = 3;
}

void		dda_algorithm(t_wolf_3d *w)
{
	while (w->ray.hit == 0)
	{
		if (w->ray.sidedist.x < w->ray.sidedist.y)
		{
			w->ray.sidedist.x += w->ray.deltadist.x;
			w->ray.map.x += w->ray.step.x;
			w->ray.side = 0;
			check_texture_x(w);
		}
		else
		{
			w->ray.sidedist.y += w->ray.deltadist.y;
			w->ray.map.y += w->ray.step.y;
			w->ray.side = 1;
			check_texture_y(w);
		}
		if (w->player.world_map[w->ray.map.x][w->ray.map.y] > 0)
			w->ray.hit = 1;
	}
	if (w->ray.side == 0)
		w->ray.perpwalldist = (w->ray.map.x - w->player.pos.x +
				(1 - w->ray.step.x) / 2) / w->ray.raydir.x;
	else
		w->ray.perpwalldist = (w->ray.map.y - w->player.pos.y +
				(1 - w->ray.step.y) / 2) / w->ray.raydir.y;
}
