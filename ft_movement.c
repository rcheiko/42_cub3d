/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:57:25 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 11:41:29 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement_w(t_mlx *d)
{
	int	x_tmp;
	int	y_tmp;

	if (d->keyw == 1)
	{
		x_tmp = d->pos_x;
		y_tmp = d->pos_y;
		d->pos_x = d->pos_x + cos(M_PI / d->val_pi) * 8;
		d->pos_y = d->pos_y - sin(M_PI / d->val_pi) * 8;
		if (d->map[(int)d->pos_y / 64][(int)d->pos_x / 64] == 1)
		{
			d->pos_x = x_tmp;
			d->pos_y = y_tmp;
		}
	}
}

void	movement_s(t_mlx *d)
{
	int	x_tmp;
	int	y_tmp;

	if (d->keys == 1)
	{
		x_tmp = d->pos_x;
		y_tmp = d->pos_y;
		d->pos_x = d->pos_x - cos(M_PI / d->val_pi) * 8;
		d->pos_y = d->pos_y + sin(M_PI / d->val_pi) * 8;
		if (d->map[(int)d->pos_y / 64][(int)d->pos_x / 64] == 1)
		{
			d->pos_x = x_tmp;
			d->pos_y = y_tmp;
		}
	}
}

void	movement_d(t_mlx *d)
{
	int	x_tmp;
	int	y_tmp;

	if (d->keyd == 1)
	{
		d->val_pi = 180 / (d->angle - 90);
		x_tmp = d->pos_x;
		y_tmp = d->pos_y;
		d->pos_x = d->pos_x + cos(M_PI / d->val_pi) * 8;
		d->pos_y = d->pos_y - sin(M_PI / d->val_pi) * 8;
		if (d->map[(int)d->pos_y / 64][(int)d->pos_x / 64] == 1)
		{
			d->pos_x = x_tmp;
			d->pos_y = y_tmp;
		}
	}
}

void	movement_a(t_mlx *d)
{
	int	x_tmp;
	int	y_tmp;

	if (d->keya == 1)
	{
		d->val_pi = 180 / (d->angle + 90);
		x_tmp = d->pos_x;
		y_tmp = d->pos_y;
		d->pos_x = d->pos_x + cos(M_PI / d->val_pi) * 8;
		d->pos_y = d->pos_y - sin(M_PI / d->val_pi) * 8;
		if (d->map[(int)d->pos_y / 64][(int)d->pos_x / 64] == 1)
		{
			d->pos_x = x_tmp;
			d->pos_y = y_tmp;
		}
	}
}

void	movement_fl_esc(t_mlx *d)
{
	if (d->keyfg == 1)
	{
		d->angle = d->angle + 5;
		verif_angle(d);
	}
	if (d->keyfd == 1)
	{
		d->angle = d->angle - 5;
		verif_angle(d);
	}
	if (d->keyesc == 1)
	{
		free_all(d);
		exit(0);
	}
}
