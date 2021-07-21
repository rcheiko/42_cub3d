/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:58:38 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 11:55:30 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	haut_gauche_calc(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	convertdeg(d);
	d->h_inter_y = (pos_y / 64) * (64);
	d->h_inter_x = pos_x + (pos_y - d->h_inter_y) / d->valeur;
	d->v_inter_x = (pos_x / 64) * (64);
	d->v_inter_y = pos_y + (pos_x - d->v_inter_x) * d->valeur;
}

void	haut_droite_calc(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	convertdeg(d);
	d->h_inter_y = (pos_y / 64) * (64);
	d->h_inter_x = pos_x + (pos_y - d->h_inter_y) / d->valeur;
	d->v_inter_x = (pos_x / 64) * (64) + 64;
	d->v_inter_y = pos_y + (pos_x - d->v_inter_x) * d->valeur;
}

void	bas_droite_calc(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	convertdeg(d);
	d->h_inter_y = (pos_y / 64) * (64) + 64;
	d->h_inter_x = pos_x + (pos_y - d->h_inter_y) / d->valeur;
	d->v_inter_x = (pos_x / 64) * (64) + 64;
	d->v_inter_y = pos_y + (pos_x - d->v_inter_x) * d->valeur;
}

void	bas_gauche_calc(t_mlx *d)
{
	int			pos_x;
	int			pos_y;

	pos_x = d->pos_x;
	pos_y = d->pos_y;
	convertdeg(d);
	d->h_inter_y = (pos_y / 64) * (64) + 64;
	d->h_inter_x = pos_x + (pos_y - d->h_inter_y) / d->valeur;
	d->v_inter_x = (pos_x / 64) * (64);
	d->v_inter_y = pos_y + (pos_x - d->v_inter_x) * d->valeur;
}
