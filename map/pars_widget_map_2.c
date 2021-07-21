/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:44:19 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/01 14:51:32 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	pick_east(t_mlx *d, char *str)
{
	char	**result;

	if (d->ea)
		return (print_error(1));
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "EA") != 0)
		return (print_error(2));
	if (result[1][0] != '.' || result[1][1] != '/')
		return (print_error(4));
	d->ea = ft_strdup(result[1]);
	free_position(result);
	return (0);
}

int	pick_sprite(t_mlx *d, char *str)
{
	char	**result;

	if (d->s)
		return (print_error(1));
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "S") != 0)
		return (print_error(2));
	if (result[1][0] != '.' || result[1][1] != '/')
		return (print_error(4));
	d->s = ft_strdup(result[1]);
	free_position(result);
	return (0);
}

int	pick_floor(t_mlx *d, char *str)
{
	char	**result;
	char	**rgb;
	int		i;

	if (d->floor_r)
		return (print_error(1));
	i = -1;
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "F") != 0)
		return (print_error(2));
	rgb = ft_split(result[1], ',');
	while (++i < 3)
	{
		if ((verif_digit(rgb[i]) == 1) || (ft_strlen(rgb[i]) > 3))
			return (print_error(5));
	}
	d->floor_r = ft_atoi(rgb[0]);
	d->floor_g = ft_atoi(rgb[1]);
	d->floor_b = ft_atoi(rgb[2]);
	if (verif_floor(d) == 1)
		return (1);
	free_floor(rgb, result);
	return (0);
}

int	pick_ceil(t_mlx *d, char *str)
{
	char	**result;
	char	**rgb;
	int		i;

	if (d->ceil_r)
		return (print_error(1));
	i = -1;
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "C") != 0)
		return (print_error(2));
	rgb = ft_split(result[1], ',');
	while (++i < 3)
	{
		if (verif_digit(rgb[i]) == 1 || ft_strlen(rgb[i]) > 3)
			return (print_error(5));
	}
	if (verif_ceil(d) == 1)
		return (1);
	d->ceil_r = ft_atoi(rgb[0]);
	d->ceil_g = ft_atoi(rgb[1]);
	d->ceil_b = ft_atoi(rgb[2]);
	free_ceil(rgb, result);
	return (0);
}
