/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:42:59 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/01 14:51:43 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	pick_resolution(t_mlx *d, char *str)
{
	char	**result;

	if (d->largeur)
		return (print_error(1));
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "R") != 0)
		return (print_error(2));
	if (verif_digit(result[1]) == 1)
		return (print_error(3));
	if (verif_digit(result[2]) == 1)
		return (print_error(3));
	d->longueur = ft_atoi(result[1]);
	d->largeur = ft_atoi(result[2]);
	if (d->longueur > 1920)
		d->longueur = 1920;
	if (d->largeur > 1080)
		d->largeur = 1080;
	if (d->longueur <= 0 || d->largeur <= 0)
		return (print_error(3));
	free_resolution(result);
	return (0);
}

int	pick_north(t_mlx *d, char *str)
{
	char	**result;

	if (d->no)
		return (print_error(1));
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "NO") != 0)
		return (print_error(2));
	if (result[1][0] != '.' || result[1][1] != '/')
		return (print_error(4));
	d->no = ft_strdup(result[1]);
	free_position(result);
	return (0);
}

int	pick_south(t_mlx *d, char *str)
{
	char	**result;

	if (d->so)
		return (print_error(1));
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "SO") != 0)
		return (print_error(2));
	if (result[1][0] != '.' || result[1][1] != '/')
		return (print_error(4));
	d->so = ft_strdup(result[1]);
	free_position(result);
	return (0);
}

int	pick_west(t_mlx *d, char *str)
{
	char	**result;

	if (d->we)
		return (print_error(1));
	result = ft_split(str, ' ');
	if (ft_strcmp(result[0], "WE") != 0)
		return (print_error(2));
	if (result[1][0] != '.' || result[1][1] != '/')
		return (print_error(4));
	d->we = ft_strdup(result[1]);
	free_position(result);
	return (0);
}
