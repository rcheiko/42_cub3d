/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 09:11:19 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/26 10:42:24 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_mlx *d)
{
	int	i;

	i = -1;
	free(d->no);
	d->no = NULL;
	free(d->so);
	d->so = NULL;
	free(d->we);
	d->we = NULL;
	free(d->ea);
	d->ea = NULL;
	free(d->s);
	d->s = NULL;
	free(d->spr);
	free(d->sprr);
	free(d->ray_wall);
	while (++i <= d->col_y)
		free(d->map[i]);
	free(d->map);
}

void	free_ceil(char **rgb, char **result)
{
	int	i;

	i = -1;
	while (rgb[++i])
		free (rgb[i]);
	free (rgb);
	i = -1;
	while (result[++i])
		free (result[i]);
	free (result);
}

void	free_floor(char **rgb, char **result)
{
	int	i;

	i = -1;
	while (rgb[++i])
		free (rgb[i]);
	free (rgb);
	i = -1;
	while (result[++i])
		free (result[i]);
	free (result);
}

void	free_position(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	free_resolution(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free (result[i]);
		i++;
	}
	free (result);
}
