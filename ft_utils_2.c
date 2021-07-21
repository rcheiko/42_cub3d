/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:15:11 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/22 11:01:08 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_convert(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	my_mlx_texture_put(t_mlx *d, int x, int y, int i)
{
	char	*dst;

	dst = d->tex[i].ad_tex
		+ (y * d->tex[i].length_tex + x * (d->tex[i].bits_text / 8));
	return (*(unsigned int *) dst);
}

int	my_mlx_sprite_put(t_mlx *d, int x, int y, int i)
{
	char	*dst;

	dst = d->sprr[i].ad_spr
		+ (y * d->sprr[i].length_spr + x * (d->sprr[i].bits_spr / 8));
	return (*(unsigned int *) dst);
}

int	my_mlx_pixel_pick(t_mlx *d, int x, int y)
{
	char	*dst;

	dst = d->addr
		+ (y * d->line_length + x * (d->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}

char	*free_protected(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
	return (str);
}
