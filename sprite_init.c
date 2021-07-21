/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:11:20 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 12:55:35 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_init_2(t_mlx *d, double dist_spr)
{
	int	i;

	d->p_x = d->longueur * d->spr_dif_ang / 60;
	i = 0;
	d->x_tmp = 32;
	while (i < d->spr_height / 2)
	{
		if ((d->p_x > 0 && d->p_x < d->longueur)
			&& (d->ray_wall[(int)d->p_x] > dist_spr))
			draw_sprite(d);
		i++;
		d->p_x--;
		d->x_tmp -= 64 / d->spr_height;
	}
}
