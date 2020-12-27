/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 01:36:11 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/16 04:02:33 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void		clear_data_tab(int *tab)
{
	int		i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		tab[i] = 0;
		i++;
	}
}

int			line_numb(char *argv)
{
	int		n;
	char	*line;
	int		fd;
	int		ret;

	n = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		n++;
		free(line);
	}
	close(fd);
	return (n);
}

int			ft_strlen_2_dim(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

size_t		check(t_wolf_3d *w, int **map, int n, int i)
{
	static int nb;

	if (i == 0)
	{
		nb = n;
		return (n);
	}
	else if (n >= nb)
		return (nb);
	else if (n < nb)
	{
		ft_putstr("ヽ(｀⌒´メ)ノ EROOR: Something wrong with the maps ヽ(｀⌒´メ)ノ\n");
		free_map2(map, i);
		free(w);
		exit(1);
	}
	else
		return (n);
}

int			*values(char **tab, size_t len)
{
	size_t	i;
	int		*map;

	i = -1;
	if (!(map = (int *)malloc(sizeof(int) * (len + 1))))
		return (0);
	while (++i < len)
	{
		if (ft_atoi(tab[i]) >= 0 && ft_atoi(tab[i]) <= 5)
			map[i] = ft_atoi(tab[i]);
		else
			map[i] = 0;
	}
	return (map);
}
