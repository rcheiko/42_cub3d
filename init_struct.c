/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:54:54 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 12:13:33 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_mlx *d)
{
	d->pos_x = 0;
	d->pos_y = 0;
	d->bits_per_pixel = 0;
	d->line_length = 0;
	d->endian = 0;
	d->keyw = 0;
	d->keys = 0;
	d->keya = 0;
	d->keyd = 0;
	d->keyesc = 0;
	d->keyfg = 0;
	d->keyfd = 0;
	d->h_inter_x = 0;
	d->h_inter_y = 0;
	d->v_inter_x = 0;
	d->v_inter_y = 0;
}

void	init_struct_2(t_mlx *d)
{
	d->angle = 0;
	d->val_pi = 0;
	d->valeur = 0;
	d->k = 0;
	d->ray = 0;
	d->angle_tmp = 0;
	d->spr_angle = 0;
	d->spr_dif_ang = 0;
	d->dist = 0;
	d->p_y = 0;
	d->hor = 0;
	d->ver = 0;
	d->spr_total = 0;
	d->spr_height = 0;
	d->save = 0;
}

void	init_struct_map(t_mlx *d)
{
	d->largeur = 0;
	d->longueur = 0;
	d->no = NULL;
	d->so = NULL;
	d->we = NULL;
	d->ea = NULL;
	d->s = NULL;
	d->floor_r = 0;
	d->floor_g = 0;
	d->floor_b = 0;
	d->ceil_r = 0;
	d->ceil_g = 0;
	d->ceil_b = 0;
	d->i_malloc = 0;
	d->row_x = 0;
	d->col_y = 0;
	d->x_perso = 0;
	d->y_perso = 0;
	d->perso = 0;
}

void	init_struct_mini_map(t_mlx *d)
{
	d->x = 0;
	d->y = 0;
	d->k = 0;
	d->h_x = 0;
	d->h_y = 0;
	d->v_x = 0;
	d->v_y = 0;
	d->val_pi_map = 0;
}

void	init_all(t_mlx *d)
{
	init_struct(d);
	init_struct_2(d);
	init_struct_map(d);
	init_struct_mini_map(d);
}
