/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:22:33 by ayagoumi          #+#    #+#             */
/*   Updated: 2020/12/16 04:02:50 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void	inner_correction(int **map, int n, int m)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (map[i][j] == 0 && (i == 0 || j == 0))
				map[i][j] = 1;
			else if (map[i][j] == 0 && (i == 23 || j == 23))
				map[i][j] = 1;
			else if (map[i][j] < 0 || map[i][j] > 5)
				map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	correction(t_wolf_3d *w, int **map, int n, int m)
{
	if (n != m)
	{
		ft_putstr("ヽ(｀⌒´メ)ノEROOR: Map should be 24 x 24ヽ(｀⌒´メ)ノ\n");
		free(w);
		exit(1);
	}
	inner_correction(map, n, m);
}

void	show_error2(t_wolf_3d *w, char *str)
{
	ft_putstr("\033[1;31m                ERROR                    \033[0m\n");
	ft_putstr("                  ");
	ft_putstr(str);
	ft_putstr("\n\033[1;31m");
	ft_putstr("ヽ(｀⌒´メ)ノ  You can't fool me  ヽ(｀⌒´メ)ノ\n");
	ft_putstr("ヽ(｀⌒´メ)ノ   No  map is here   ヽ(｀⌒´メ)ノ\n");
	ft_putstr("ヽ(｀⌒´メ)ノ    File is empty    ヽ(｀⌒´メ)ノ");
	ft_putstr("\033[0m");
	ft_putchar('\n');
	free(w);
	exit(1);
}

int		**get_map(t_wolf_3d *w, int **map, int fd, char **av)
{
	char	*line;
	char	**tab;
	int		n;
	int		i;
	int		m;

	m = line_numb(av[1]);
	if (m < 1)
		show_error2(w, av[1]);
	if (!(map = (int **)malloc(sizeof(int *) * (m + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_split_whitespaces(line);
		n = ft_strlen_2_dim(tab);
		n = check(w, map, n, i);
		map[i] = values(tab, n);
		free(line);
		free_map(tab, n);
		tab = NULL;
		i++;
	}
	correction(w, map, n, m);
	return (map);
}
