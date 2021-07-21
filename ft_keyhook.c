/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:57:25 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 12:06:55 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyhook(t_mlx *d)
{
	d->val_pi = 180 / d->angle;
	movement_w(d);
	movement_s(d);
	movement_a(d);
	movement_d(d);
	movement_fl_esc(d);
	return (0);
}

int	keypress(int keycode, t_mlx *d)
{
	if (keycode == 13)
		d->keyw = 1;
	if (keycode == 0)
		d->keya = 1;
	if (keycode == 1)
		d->keys = 1;
	if (keycode == 2)
		d->keyd = 1;
	if (keycode == 53)
		d->keyesc = 1;
	if (keycode == 123)
		d->keyfg = 1;
	if (keycode == 124)
		d->keyfd = 1;
	return (0);
}

int	keyrelease(int keycode, t_mlx *d)
{
	if (keycode == 13)
		d->keyw = 0;
	if (keycode == 0)
		d->keya = 0;
	if (keycode == 1)
		d->keys = 0;
	if (keycode == 2)
		d->keyd = 0;
	if (keycode == 123)
		d->keyfg = 0;
	if (keycode == 124)
		d->keyfd = 0;
	return (0);
}

int	key_exit(t_mlx *d)
{
	d->angle = d->angle;
	exit (0);
}
