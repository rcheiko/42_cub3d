/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:58:38 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 11:55:12 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	haut_gauche(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	haut_gauche_calc(d);
	if (d->angle == 180)
	{
		d->v_inter_y = pos_y;
		while (d->map[(int)d->v_inter_y / 64][(int)d->v_inter_x / 64 - 1] != 1)
			d->v_inter_x -= 64;
		d->h_inter_x = d->v_inter_x - 1;
		d->h_inter_y = d->v_inter_y - 1;
	}
	else
		haut_gauche_2(d);
}

void	haut_droite(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	haut_droite_calc(d);
	if (d->angle == 90)
	{
		d->h_inter_x = pos_x;
		while (d->map[(int)d->h_inter_y / 64 - 1][(int)d->h_inter_x / 64] != 1)
			d->h_inter_y -= 64;
		d->v_inter_x = d->h_inter_x;
		d->v_inter_y = d->h_inter_y;
	}
	else if (d->angle == 0)
	{
		d->v_inter_y = pos_y;
		while (d->map[(int)d->v_inter_y / 64][(int)d->v_inter_x / 64] != 1)
			d->v_inter_x += 64;
		d->h_inter_x = d->v_inter_x + 1;
		d->h_inter_y = d->v_inter_y;
	}
	else
		haut_droite_2(d);
}

void	bas_droite(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	bas_droite_calc(d);
	if (d->angle == 270)
	{
		d->h_inter_x = pos_x;
		while (d->map[(int)d->h_inter_y / 64][(int)d->h_inter_x / 64] != 1)
			d->h_inter_y += 64;
		d->v_inter_x = d->h_inter_x;
		d->v_inter_y = d->h_inter_y;
	}
	else if (d->angle > 270 && d->angle < 360)
		bas_droite_2(d);
}

void	bas_gauche(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	bas_gauche_calc(d);
	while ((d->h_inter_x / 64 > 0 && d->h_inter_y / 64 < d->col_y)
		&& (d->map[(int)d->h_inter_y / 64][(int)d->h_inter_x / 64] != 1))
	{
		d->h_inter_x += -64 / d->valeur;
		d->h_inter_y += 64;
	}
	while ((d->v_inter_x / 64 > 0 && d->v_inter_y / 64 < d->col_y)
		&& (d->map[(int)d->v_inter_y / 64][(int)d->v_inter_x / 64 - 1] != 1))
	{
		d->v_inter_x += -64;
		d->v_inter_y += 64 * (d->valeur);
	}
}
