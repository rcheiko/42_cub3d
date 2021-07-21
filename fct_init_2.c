/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:01:42 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 15:58:21 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_parsing(t_mlx *d, int fd, char **av)
{
	init_all(d);
	if (traitement_total(d, fd) == 1)
		return (1);
	if (find_malloc(d, fd) == 1)
		return (1);
	if (fin_malloc(d, fd) == 1)
		return (1);
	fd = get_i_map(d, av);
	if (fill_map(d, fd) == 1)
		return (1);
	if (check_map(d) == 1)
		return (1);
	if (d->perso == 0)
		return (print_error_2(1));
	del_perso(d);
	angle_character(d);
	if (malloc_spr(d) == 1)
		return (1);
	d->ray_wall = malloc(sizeof(double) * d->longueur);
	return (0);
}

int	init_tex_spr(t_mlx *d)
{
	if (init_tex(d) == 1)
		return (1);
	if (init_spr(d) == 1)
		return (1);
	return (0);
}
