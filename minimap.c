/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:58:07 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/22 16:25:49 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	taille_mini_map(t_mlx *d)
{
	d->k = floor(d->longueur / 64);
	if (d->row_x > 20)
		d->k /= 2;
	if (d->col_y > 20)
		d->k /= 2;
}

void	affcarre(t_mlx *d, int a)
{
	int	x;
	int	y;

	x = d->x * d->k;
	y = d->y * d->k;
	while (y < (d->y + 1) * d->k)
	{
		x = d->x * d->k;
		while (x < (d->x + 1) * d->k)
		{
			if (a == 1)
				my_mlx_pixel_put(d, x, y, 0x606060);
			if (a == 2)
				my_mlx_pixel_put(d, x, y, 0x235A8C);
			if (a == 8)
				my_mlx_pixel_put(d, x, y, 0xB0F2B6);
			if (x % d->k == 0 || y % d->k == 0)
				my_mlx_pixel_put(d, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	affmap(t_mlx *d)
{
	d->y = 0;
	while (d->map[d->y] && d->y <= d->col_y)
	{
		d->x = 0;
		while (d->map[d->y][d->x] && d->x <= d->x_map[d->y])
		{
			if ((d->map[d->y][d->x]) == 1)
				affcarre(d, 1);
			if ((d->map[d->y][d->x]) == 2)
				affcarre(d, 2);
			if ((d->map[d->y][d->x]) == 8)
				affcarre(d, 8);
			d->x++;
		}
		d->y++;
	}
}
