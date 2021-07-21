/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:01:05 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 12:20:18 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_height(t_mlx *d)
{
	double	result;
	double	result2;

	result = 0;
	result2 = 0;
	result = degtorad(d->angle, result);
	result2 = degtorad(d->angle_tmp, result2);
	d->camera_h = d->longueur / 2;
	d->hor = sqrt(pow(d->h_inter_x - d->pos_x, 2)
			+ pow(d->h_inter_y - d->pos_y, 2));
	d->ver = sqrt(pow(d->v_inter_x - d->pos_x, 2)
			+ pow(d->v_inter_y - d->pos_y, 2));
	d->dist = fmin(d->hor, d->ver);
	d->ray_wall[(int)d->p_x] = d->dist;
	d->dist = d->dist * cos(result2 - result);
	d->dist_plan = d->camera_h / tan(30 * (M_PI / 180));
	d->wall_height = 64 / d->dist * d->dist_plan;
	d->wall_height = ceil(d->wall_height);
}

void	draw_walls(t_mlx *d)
{
	int	i;

	i = 0;
	d->p_y_y = 0;
	d->p_y = d->largeur / 2 - d->wall_height / 2;
	while (d->p_y > 0)
	{
		my_mlx_pixel_put(d,
			d->p_x, d->p_y, rgb_convert(d->ceil_r, d->ceil_g, d->ceil_b));
		d->p_y--;
	}
	d->p_y = d->largeur / 2 - d->wall_height / 2;
	draw_walls_4(d);
}

void	draw_walls_2(t_mlx *d)
{
	if (d->angle >= 0 && d->angle <= 90)
	{
		if (d->hor > d->ver)
			d->color_tex = my_mlx_texture_put(d,
					(int)d->v_inter_y % 64, (int)d->p_y_y, 3);
		else
			d->color_tex = my_mlx_texture_put(d,
					(int)d->h_inter_x % 64, (int)d->p_y_y, 0);
	}
	else if (d->angle >= 270 && d->angle < 360)
	{
		if (d->hor > d->ver)
			d->color_tex = my_mlx_texture_put(d,
					(int)d->v_inter_y % 64, (int)d->p_y_y, 3);
		else
			d->color_tex = my_mlx_texture_put(d,
					(int)d->h_inter_x % 64, (int)d->p_y_y, 1);
	}
}

void	draw_walls_3(t_mlx *d)
{
	if (d->angle <= 180 && d->angle > 90)
	{
		if (d->hor > d->ver)
			d->color_tex = my_mlx_texture_put(d,
					(int)d->v_inter_y % 64, (int)d->p_y_y, 2);
		else
			d->color_tex = my_mlx_texture_put(d,
					(int)d->h_inter_x % 64, (int)d->p_y_y, 0);
	}
	else if (d->angle > 180 && d->angle < 270)
	{
		if (d->hor > d->ver)
			d->color_tex = my_mlx_texture_put(d,
					(int)d->v_inter_y % 64, (int)d->p_y_y, 2);
		else
			d->color_tex = my_mlx_texture_put(d,
					(int)d->h_inter_x % 64, (int)d->p_y_y, 1);
	}
}

void	draw_walls_4(t_mlx *d)
{
	int	i;

	i = 0;
	while (i < d->wall_height)
	{
		if ((d->p_x < 0 || d->p_x > d->longueur)
			|| (d->p_y < 0 || d->p_y > d->largeur))
			break ;
		draw_walls_2(d);
		draw_walls_3(d);
		my_mlx_pixel_put(d, d->p_x, d->p_y, d->color_tex);
		d->p_y++;
		d->p_y_y += 64.0 / d->wall_height;
		i++;
		if (i == d->wall_height)
		{
			while (d->p_y < d->largeur)
			{
				my_mlx_pixel_put(d,
					d->p_x, d->p_y,
					rgb_convert(d->floor_r, d->floor_g, d->floor_b));
				d->p_y++;
			}
		}
	}
}
