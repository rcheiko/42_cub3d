/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:35:05 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/22 11:47:24 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_malloc(t_mlx *d, int fd)
{
	int		i;
	int		ret;
	char	*str;

	ret = 1;
	while (ret > 0)
	{
		i = 0;
		ret = get_next_line(fd, &str);
		d->i_malloc++;
		while (str[i])
		{
			if (str[i] != '1' && str[i] != ' ' && str[i] != '\n')
				return (print_error(7));
			i++;
		}
		if (i == ft_strlen(str) && ft_strlen(str) != 0)
		{
			d->i_malloc--;
			free_protected(str);
			return (0);
		}
		str = free_protected(str);
	}
	return (print_error(7));
}

int	fin_malloc(t_mlx *d, int fd)
{
	int		ret;
	char	*str;

	ret = 1;
	d->i_map = d->i_malloc;
	d->i_malloc = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		d->i_malloc++;
		if (ft_strcmp("", str) == 0)
			return (print_error(10));
		str = free_protected(str);
	}
	d->col_y = d->i_malloc;
	d->map = malloc(sizeof(int *) * (d->i_malloc + 2));
	d->x_map = malloc(sizeof(int) * (d->i_malloc + 2));
	if (d->map == NULL)
		return (print_error(8));
	return (0);
}

int	get_i_map(t_mlx *d, char **av)
{
	int		fd;
	int		ret;
	char	*str;

	fd = open(av[1], O_RDONLY);
	while (d->i_map > 0)
	{
		ret = get_next_line(fd, &str);
		str = free_protected(str);
		d->i_map--;
	}
	return (fd);
}

int	cond_fill_map(t_mlx *d, char *str, int i, int j)
{
	if (str[i] == ' ')
		d->map[j][i] = 9;
	else if (str[i] == '1')
		d->map[j][i] = 1;
	else if (str[i] == '0')
		d->map[j][i] = 8;
	else if (str[i] == 'N')
		d->map[j][i] = 3;
	else if (str[i] == 'S')
		d->map[j][i] = 4;
	else if (str[i] == 'E')
		d->map[j][i] = 5;
	else if (str[i] == 'W')
		d->map[j][i] = 6;
	else if (str[i] == '2')
		d->map[j][i] = 2;
	else
	{
		return (print_error(7));
	}
	return (0);
}

int	fill_map(t_mlx *d, int fd)
{
	int		ret;
	int		i;
	int		j;
	char	*str;

	j = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		d->x_map[j] = ft_strlen(str) - 1;
		if (ft_malloc_map(d, j) == 1)
			return (1);
		i = 0;
		while (i < ft_strlen(str))
		{
			if (cond_fill_map(d, str, i, j) == 1)
				return (1);
			i++;
		}
		compar_max(d, ft_strlen(str));
		j++;
		str = free_protected(str);
	}
	return (0);
}
