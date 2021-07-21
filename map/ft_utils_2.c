/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:03:14 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/01 14:46:32 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	print_error(int error)
{
	if (error == 1)
		write(1, "Error Duplication\n", 18);
	if (error == 2)
		write(1, "Error of String\n", 16);
	if (error == 3)
		write(1, "Error of Resolution\n", 20);
	if (error == 4)
		write(1, "Error of Path\n", 14);
	if (error == 5)
		write(1, "Error of RGB\n", 13);
	if (error == 6)
		write(1, "Error of line\n", 14);
	if (error == 7)
		write(1, "Error of map\n", 13);
	if (error == 8)
		write(1, "Error of Memory Malloc\n", 23);
	if (error == 9)
		write(1, "Error there is more than one character\n", 39);
	if (error == 10)
		write(1, "Error of map\n", 13);
	return (1);
}

int	verif_digit(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	compar_max(t_mlx *d, int l)
{
	if (d->row_x < l)
		d->row_x = l - 1;
	return (0);
}

int	ft_malloc_map(t_mlx *d, int j)
{
	d->map[j] = malloc(sizeof(int) * (d->x_map[j] + 2));
	if ((d->map[j]) == NULL)
		return (print_error(8));
	return (0);
}

int	check_charset(int val, char *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (check[i] - '0' == val)
			return (1);
		i++;
	}
	return (0);
}
