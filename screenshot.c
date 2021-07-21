/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:15:12 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 14:56:11 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_header(t_mlx *d, int fd)
{
	int	size;
	int	z;
	int	offset;

	size = d->largeur * d->longueur * 4 + 54;
	z = 0;
	offset = 54;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, &z, 4);
	write(fd, &offset, 4);
}

void	screenshot_header(t_mlx *d, int fd, int z)
{
	int	sizeheader;
	int	longueur;
	int	largeur;
	int	plan;
	int	bpp;

	sizeheader = 40;
	longueur = d->longueur;
	largeur = d->largeur;
	plan = 1;
	bpp = d->bits_per_pixel;
	write(fd, &sizeheader, 4);
	write(fd, &longueur, 4);
	write(fd, &largeur, 4);
	write(fd, &plan, 2);
	write(fd, &bpp, 2);
	write(fd, &z, 24);
}

void	screenshot_color(t_mlx *d, int fd)
{
	int	x;
	int	y;
	int	rgb;

	y = d->largeur;
	while (y > 1)
	{
		x = 0;
		while (x < d->longueur)
		{
			rgb = my_mlx_pixel_pick(d, x, y);
			write(fd, &rgb, 3);
			write(fd, "0", 1);
			x++;
		}
		y--;
	}
}

int	screenshot_init(t_mlx *d)
{
	int	fd;
	int	z;

	z = 0;
	fd = open("./screenshot.bmp", O_CREAT | O_WRONLY, 777);
	file_header(d, fd);
	screenshot_header(d, fd, z);
	screenshot_color(d, fd);
	exit(0);
	return (0);
}
