/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 01:28:35 by yait-el-          #+#    #+#             */
/*   Updated: 2020/12/16 03:24:27 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf_3d.h"

void	show_error1(t_wolf_3d *w)
{
	free(w);
	ft_putstr("\033[1;31m");
	ft_putstr(" : ヽ(｀⌒´メ)ノ There is no such map folder ヽ(｀⌒´メ)ノ");
	ft_putstr("\033[0m");
	ft_putchar('\n');
	exit(1);
}

void	show_error3(void)
{
	ft_putstr("\033[1;36m");
	ft_putstr("ヽ(｀⌒´メ)ノ Choose a Map from the maps folder ヽ(｀⌒´メ)ノ\n");
	ft_putstr("ヽ(｀⌒´メ)ノ   Try again using this sentence   ヽ(｀⌒´メ)ノ\n");
	ft_putstr("ヽ(｀⌒´メ)ノ   ./Wolf maps/[name-of-the-map]   ヽ(｀⌒´メ)ノ");
	ft_putstr("\033[0m");
	ft_putchar('\n');
	exit(1);
}

void	show_error_map(void)
{
	ft_putstr("\033[1;32m");
	ft_putstr("ヽ(｀⌒´メ)ノ            OOPS! Sorry            ヽ(｀⌒´メ)ノ\n");
	ft_putstr("ヽ(｀⌒´メ)ノ This Map has nowhere to stand in  ヽ(｀⌒´メ)ノ\n");
	ft_putstr("ヽ(｀⌒´メ)ノ     Please choose another one     ヽ(｀⌒´メ)ノ");
	ft_putstr("\033[0m");
	ft_putchar('\n');
	exit(1);
}
