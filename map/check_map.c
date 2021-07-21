/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:32:59 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/05 12:23:23 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	zero_map(t_mlx *d, int y, int x)
{
	if (x == 0 || y == d->col_y || y == 0)
		return (print_error(10));
	if (check_charset(d->map[y - 1][x - 1], "8123456") == 0)
		return (print_error(10));
	if (check_charset(d->map[y][x - 1], "8123456") == 0)
		return (print_error(10));
	if (check_charset(d->map[y - 1][x], "8123456") == 0)
		return (print_error(10));
	if (check_charset(d->map[y + 1][x + 1], "8123456") == 0)
		return (print_error(10));
	if (check_charset(d->map[y][x + 1], "8123456") == 0)
		return (print_error(10));
	if (check_charset(d->map[y + 1][x], "8123456") == 0)
		return (print_error(10));
	return (0);
}

int	check_map(t_mlx *d)
{
	int	y;
	int	x;

	y = -1;
	x = 0;
	while (d->map[++y] && y <= d->col_y)
	{
		while (d->map[y][x] && x <= d->x_map[y])
		{
			if (d->perso != 0 && check_charset(d->map[y][x], "3456") == 1)
				return (print_error(9));
			else if (check_charset(d->map[y][x], "3456") == 1 && d->perso == 0)
			{
				d->x_perso = x;
				d->y_perso = y;
				d->perso = d->map[y][x];
			}
			if (check_charset(d->map[y][x], "823456") == 1)
				if (zero_map(d, y, x) == 1)
					return (1);
			x++;
		}
		x = 0;
	}
	return (0);
}
