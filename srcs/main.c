/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:27:40 by ayagoumi          #+#    #+#             */
/*   Updated: 2020/12/16 03:57:59 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

/*
 **	Game loop
*/

void	game_engine(t_wolf_3d *w)
{
	while (w->game_running == 0)
	{
		process_input(w, w->player.world_map);
		update(w);
		render(w);
	}
}

/*
 ** Load the map from the file
*/

void	load_map(t_wolf_3d *w, char **av)
{
	int fd;

	if (!(fd = open(av[1], O_RDONLY)))
		show_error1(w);
	if (fd >= 3)
		w->player.world_map = get_map(w, w->player.world_map, fd, av);
	else
		show_error1(w);
}

int		main(int ac, char **av)
{
	t_wolf_3d *w;

	w = NULL;
	if (ac == 2)
	{
		if (!(w = malloc(sizeof(t_wolf_3d))))
			exit(0);
		load_map(w, av);
		load_img(w);
		w->game_running = sdl_init_win(w);
		init_perso(w);
		game_engine(w);
		sdl_quit(w);
	}
	else
		show_error3();
	return (0);
}
