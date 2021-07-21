/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:58:38 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/22 16:28:57 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	haut_gauche_2(t_mlx *d)
{
	while ((d->h_inter_x / 64 > 0 && d->h_inter_y / 64 > 0)
		&& (d->map[(int)d->h_inter_y / 64 - 1][(int)d->h_inter_x / 64] != 1))
	{
		d->h_inter_x += 64 / d->valeur;
		d->h_inter_y += -64;
	}
	while ((d->v_inter_x / 64 > 0 && d->v_inter_y / 64 > 0)
		&& (d->map[(int)d->v_inter_y / 64][(int)d->v_inter_x / 64 - 1] != 1))
	{
		d->v_inter_x -= 64;
		d->v_inter_y += 64 * (d->valeur);
	}
}

void	haut_droite_2(t_mlx *d)
{
	while ((d->h_inter_x / 64 < d->x_map[(int)d->h_inter_y / 64]
			&& d->h_inter_y / 64 > 1)
		&& (d->map[(int)d->h_inter_y / 64 - 1][(int)d->h_inter_x / 64] != 1))
	{
		d->h_inter_x += 64 / d->valeur;
		d->h_inter_y += -64;
	}
	if (d->v_inter_x / 64 > 0 && d->v_inter_y / 64 > 0)
	{
		while ((d->v_inter_x / 64 < d->x_map[(int)d->h_inter_y / 64]
				&& d->v_inter_y / 64 > 1)
			&& (d->map[(int)d->v_inter_y / 64][(int)d->v_inter_x / 64] != 1))
		{
			d->v_inter_x += 64;
			d->v_inter_y += 64 * (-d->valeur);
		}
	}
	else
	{
		d->v_inter_x = d->h_inter_x;
		d->v_inter_y = d->h_inter_y;
	}
}

void	bas_droite_2(t_mlx *d)
{
	while ((d->h_inter_x / 64 < d->x_map[(int)d->h_inter_y / 64]
			&& d->h_inter_y / 64 < d->col_y)
		&& (d->map[(int)(d->h_inter_y / 64)][(int)(d->h_inter_x / 64)] != 1))
	{
		d->h_inter_x += 64 / -d->valeur;
		d->h_inter_y += 64;
	}
	while ((d->v_inter_x / 64 < d->x_map[(int)d->h_inter_y / 64]
			&& d->v_inter_y / 64 < d->col_y)
		&& (d->map[(int)d->v_inter_y / 64][(int)d->v_inter_x / 64] != 1))
	{
		d->v_inter_x += 64;
		d->v_inter_y += 64 * (-d->valeur);
	}
}
