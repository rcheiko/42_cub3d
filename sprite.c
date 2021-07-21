/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:11:20 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 12:55:53 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_height(t_mlx *d)
{
	d->dist = sqrt(pow(d->spr[d->i].x - d->pos_x, 2)
			+ pow(d->spr[d->i].y - d->pos_y, 2));
	d->spr_height = 64 / d->dist * d->dist_plan;
	d->spr_height = ceil(d->spr_height);
}

void	draw_sprite(t_mlx *d)
{
	int		i;
	double	p_y;

	i = 0;
	p_y = 0;
	d->p_y = d->largeur / 2 - d->spr_height / 2;
	while (i < d->spr_height)
	{
		d->color_tex = my_mlx_sprite_put(d, (int)d->x_tmp % 64, p_y, 0);
		if (d->color_tex != 16645629 && (d->p_x > 0 && d->p_x < d->longueur)
			&& (d->p_y > 0 && d->p_y < d->largeur))
			my_mlx_pixel_put(d, d->p_x, d->p_y, d->color_tex);
		d->p_y++;
		p_y += 64 / d->spr_height;
		i++;
	}
}

void	draw_all_sprite(t_mlx *d)
{
	d->i = 0;
	while (d->i < d->spr_total)
	{
		sprite_init(d);
		d->i++;
	}
}

double	calc_sprite(t_mlx *d)
{
	double	dist_spr;
	double	total;

	total = 360.0;
	d->p_x = 0;
	dist_spr = 0;
	d->x_tmp = 32;
	d->spr_angle = atan2((d->spr[d->i].y - d->pos_y),
			(d->spr[d->i].x - d->pos_x));
	d->spr_angle = d->spr_angle * 180 / M_PI;
	d->spr_dif_ang = d->angle + 30 + d->spr_angle;
	if (d->spr_dif_ang < 0)
		d->spr_dif_ang = d->spr_dif_ang + total;
	if (d->spr_dif_ang + 5 > 360)
		d->spr_dif_ang = d->spr_dif_ang - total;
	d->p_x = d->longueur * d->spr_dif_ang / 60;
	dist_spr = sqrt(pow(d->spr[d->i].x - d->pos_x, 2)
			+ pow(d->spr[d->i].y - d->pos_y, 2));
	sprite_height(d);
	return (dist_spr);
}
