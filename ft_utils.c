/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:56:03 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 11:48:42 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	convertdeg(t_mlx *d)
{
	d->valeur = 0;
	if (d->angle == 90)
		d->valeur = 1 / 2 * M_PI;
	else if (d->angle == 270)
		d->valeur = 3 / 2 * M_PI;
	else if (d->angle == 0)
		d->valeur = 2 * M_PI;
	else if (d->angle == 180)
		d->valeur = M_PI;
	else if ((d->angle > 0 && d->angle < 90)
		|| (d->angle > 90 && d->angle < 180)
		|| (d->angle > 180 && d->angle < 270)
		|| (d->angle > 270 && d->angle < 360))
		d->valeur = tan(d->angle * M_PI / 180);
}

void	verif_angle(t_mlx *d)
{
	double	total;

	total = 360.0;
	if (d->angle < 0)
		d->angle = d->angle + total;
	if (d->angle > 360)
		d->angle = d->angle - total;
}

void	angle_character(t_mlx *d)
{
	if (d->perso == 5)
		d->angle = 0;
	if (d->perso == 3)
		d->angle = 90;
	if (d->perso == 6)
		d->angle = 180;
	if (d->perso == 4)
		d->angle = 270;
	d->pos_x = (d->x_perso + 0.5) * 64;
	d->pos_y = (d->y_perso + 0.5) * 64;
}

double	degtorad(double angle, double result)
{
	result = (angle * M_PI) / 180;
	return (result);
}
