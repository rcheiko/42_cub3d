/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:08:03 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/02 12:24:26 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	traitement(t_mlx *d, char *str)
{
	int	error;

	error = 0;
	if (ft_strlen(str) == 0)
		return (3);
	else if (str[0] == 'R')
		error = pick_resolution(d, str);
	else if (str[0] == 'N' && str[1] == 'O')
		error = pick_north(d, str);
	else if (str[0] == 'S' && str[1] == 'O')
		error = pick_south(d, str);
	else if (str[0] == 'W' && str[1] == 'E')
		error = pick_west(d, str);
	else if (str[0] == 'E' && str[1] == 'A')
		error = pick_east(d, str);
	else if (str[0] == 'S')
		error = pick_sprite(d, str);
	else if (str[0] == 'F')
		error = pick_floor(d, str);
	else if (str[0] == 'C')
		error = pick_ceil(d, str);
	else
		return (print_error(6));
	return (error);
}

int	traitement_total(t_mlx *d, int fd)
{
	int		error;
	int		ret;
	int		i;
	char	*str;

	error = 0;
	str = NULL;
	ret = 1;
	i = 0;
	while (ret > 0 && error == 0 && i < 8)
	{
		ret = get_next_line(fd, &str);
		error = traitement(d, str);
		if (error == 1)
			return (1);
		else if (error != 3)
			i++;
		error = 0;
		d->i_malloc++;
		free_protected(str);
	}
	return (0);
}
