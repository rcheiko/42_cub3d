/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:01:42 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/26 10:42:45 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_all(t_mlx *d)
{
	d->val_pi = 180 / d->angle;
	if (d->angle >= 0 && d->angle <= 90)
		haut_droite(d);
	else if (d->angle >= 270 && d->angle < 360)
		bas_droite(d);
	else if (d->angle <= 180 && d->angle > 90)
		haut_gauche(d);
	else if (d->angle > 180 && d->angle < 270)
		bas_gauche(d);
}

void	angle(t_mlx *d)
{
	double	i;

	i = 0;
	d->angle_tmp = d->angle;
	d->angle += 30;
	d->ray = 60 / d->longueur;
	d->p_x = 0;
	mlx_clear_window(d->mlx, d->window);
	while (i < 60)
	{
		draw_all(d);
		wall_height(d);
		draw_walls(d);
		d->angle = d->angle - d->ray;
		verif_angle(d);
		d->p_x++;
		i += d->ray;
	}
	d->angle = d->angle_tmp;
}

void	sprite_init(t_mlx *d)
{
	int		i;
	double	dist_spr;

	i = 0;
	dist_spr = calc_sprite(d);
	while (i < d->spr_height / 2)
	{
		if ((d->p_x > 0 && d->p_x < d->longueur)
			&& (d->ray_wall[(int)d->p_x] > dist_spr))
			draw_sprite(d);
		i++;
		d->p_x++;
		d->x_tmp += 64 / d->spr_height;
	}
	sprite_init_2(d, dist_spr);
}

int	aff_perso(t_mlx *d)
{
	keyhook(d);
	angle(d);
	fill_spr(d);
	sort_tab(d);
	draw_all_sprite(d);
	taille_mini_map(d);
	affmap(d);
	my_mlx_pixel_put(d,
		d->pos_x / 64 * d->k, d->pos_y / 64 * d->k, 0xFF0000);
	my_mlx_pixel_put(d,
		d->pos_x / 64 * d->k + 1, d->pos_y / 64 * d->k, 0xFF0000);
	my_mlx_pixel_put(d,
		d->pos_x / 64 * d->k, d->pos_y / 64 * d->k + 1, 0xFF0000);
	my_mlx_pixel_put(d,
		d->pos_x / 64 * d->k + 1, d->pos_y / 64 * d->k + 1, 0xFF0000);
	barre_de_vie(d);
	barre_de_vie_3(d);
	mlx_put_image_to_window(d->mlx, d->window, d->img, 0, 0);
	if (d->save == 1)
		screenshot_init(d);
	mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, d->longueur, d->largeur);
	d->addr = mlx_get_data_addr(d->img,
			&d->bits_per_pixel, &d->line_length, &d->endian);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_mlx	d;

	if (ac == 1 || (ac > 2 && ft_strcmp("--save", av[2]) != 0))
		return (print_error_2(4));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (print_error_2(5));
	if (init_parsing(&d, fd, av) == 1)
		return (0);
	if (ac > 2 && ft_strcmp(av[2], "--save") == 0)
		d.save = 1;
	d.mlx = mlx_init();
	d.window = mlx_new_window(d.mlx, d.longueur, d.largeur, "CUB3D");
	d.img = mlx_new_image(d.mlx, d.longueur, d.largeur);
	d.addr = mlx_get_data_addr(d.img,
			&d.bits_per_pixel, &d.line_length, &d.endian);
	if (init_tex_spr(&d) == 1)
		return (0);
	mlx_hook(d.window, 2, 0, keypress, &d);
	mlx_hook(d.window, 3, 1, keyrelease, &d);
	mlx_hook(d.window, 17, 0, key_exit, &d);
	mlx_loop_hook(d.mlx, aff_perso, &d);
	mlx_loop(d.mlx);
	return (0);
}
