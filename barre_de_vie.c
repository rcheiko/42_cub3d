/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:58:07 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/22 11:47:02 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	barre_de_vie(t_mlx *d)
{
	int	haut;
	int	haut_b;
	int	larg_b;

	haut = d->largeur - 15;
	haut_b = haut / 1.02;
	larg_b = d->longueur * 0.1;
	while (haut > haut_b)
	{
		my_mlx_pixel_put(d, 15, haut, 0x000000);
		haut--;
	}
	while (15 < larg_b)
	{
		my_mlx_pixel_put(d, larg_b, haut, 0x000000);
		larg_b--;
	}
}

void	barre_de_vie_2(t_mlx *d)
{
	int	haut;
	int	haut_b;
	int	larg_b;

	larg_b = d->longueur * 0.1;
	haut = d->largeur - 15;
	haut_b = haut / 1.02;
	while (haut >= haut_b)
	{
		my_mlx_pixel_put(d, larg_b, haut, 0x000000);
		haut--;
	}
	while (larg_b > 15)
	{
		my_mlx_pixel_put(d, larg_b, (int)d->largeur - 15, 0x000000);
		larg_b--;
	}
}

void	barre_de_vie_3(t_mlx *d)
{
	int	haut;
	int	haut_b;
	int	larg_b;

	barre_de_vie(d);
	barre_de_vie_2(d);
	haut = d->largeur - 16;
	haut_b = haut / 1.02;
	larg_b = (d->longueur - 1) * 0.10;
	while (15 < larg_b)
	{
		haut = d->largeur - 16;
		while (haut > haut_b + 1)
		{
			my_mlx_pixel_put(d, larg_b, haut, 0xFF0000);
			haut--;
		}
		larg_b--;
	}
}
