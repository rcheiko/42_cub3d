/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_widget_map_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:29:01 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/02 12:27:30 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	verif_floor(t_mlx *d)
{
	if (d->floor_r > 255 || d->floor_g > 255 || d->floor_b > 255)
		return (print_error(5));
	if (d->floor_r < 0 || d->floor_g < 0 || d->floor_b < 0)
		return (print_error(5));
	return (0);
}

int	verif_ceil(t_mlx *d)
{
	if (d->ceil_r > 255 || d->ceil_g > 255 || d->ceil_b > 255)
		return (print_error(5));
	if (d->ceil_r < 0 || d->ceil_g < 0 || d->ceil_b < 0)
		return (print_error(5));
	return (0);
}

int	del_perso(t_mlx *d)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (d->map[y] && y < d->col_y)
	{
		x = 0;
		while (d->map[y][x] && x < d->x_map[y])
		{
			if (check_charset(d->map[y][x], "3456") == 1)
			{
				d->map[y][x] = 8;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}
