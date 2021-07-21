/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:26:07 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 12:22:36 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fct_mal_spr(t_mlx *d)
{
	d->spr = malloc(sizeof(t_spr) * d->spr_total);
	if (d->spr == NULL)
		return (print_error(8));
	d->sprr = malloc(sizeof(t_sprr) * d->spr_total);
	if (d->sprr == NULL)
		return (print_error(8));
	return (0);
}

int	malloc_spr(t_mlx *d)
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
			if (d->map[y][x] == 2)
				d->spr_total++;
			x++;
		}
		y++;
	}
	if (fct_mal_spr(d) == 1)
		return (1);
	return (0);
}

void	fill_spr(t_mlx *d)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (d->map[y] && y < d->col_y)
	{
		x = 0;
		while (d->map[y][x] && x < d->x_map[y])
		{
			if (d->map[y][x] == 2)
			{
				d->spr[i].y = (y + 0.5) * 64;
				d->spr[i].x = (x + 0.5) * 64;
				d->spr[i].dist = sqrt(pow(d->spr[i].x - d->pos_x, 2)
						+ pow(d->spr[i].y - d->pos_y, 2));
				i++;
			}
			x++;
		}
		y++;
	}
}

void	sort_tab(t_mlx *d)
{
	int		i;
	t_spr	tmp;

	i = 0;
	while ((i + 1) < d->spr_total)
	{
		if (d->spr[i].dist < d->spr[i + 1].dist)
		{
			tmp = d->spr[i + 1];
			d->spr[i + 1] = d->spr[i];
			d->spr[i] = tmp;
			i = -1;
		}
		i++;
	}
}

int	init_spr(t_mlx *d)
{
	int	i;

	i = 0;
	while (i < d->spr_total)
	{
		d->sprr[i].img_spr = mlx_xpm_file_to_image(d->mlx,
				d->s, &d->sprr[i].img_width_spr, &d->sprr[i].img_height_spr);
		if (d->sprr[i].img_spr == NULL)
			return (print_error_2(3));
		d->sprr[i].ad_spr = mlx_get_data_addr(d->sprr[i].img_spr,
				&d->sprr[i].bits_spr,
				&d->sprr[i].length_spr, &d->sprr[i].endian_spr);
		i++;
	}
	return (0);
}
