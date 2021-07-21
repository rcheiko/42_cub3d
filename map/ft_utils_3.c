/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:57:45 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/26 10:43:07 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_int(int *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	i--;
	return (i);
}

size_t	ft_strlen_mal(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		i--;
	}
	else
		i = 1;
	return (i);
}

int	print_error_2(int error)
{
	if (error == 1)
		write(1, "Error We Need One Character\n", 28);
	if (error == 2)
		write(1, "Error in the texture\n", 21);
	if (error == 3)
		write(1, "Error in the sprite\n", 20);
	if (error == 4)
		write(1, "Error Need 2 Arguments\n", 24);
	if (error == 5)
		write(1, "Error of file\n", 14);
	return (1);
}
