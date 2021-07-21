/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:08 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/20 12:23:59 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_tex_no(t_mlx *d)
{
	d->tex[0].img_tex = mlx_xpm_file_to_image(d->mlx,
			d->no, &d->tex[0].img_width_tex, &d->tex[0].img_height_tex);
	if (d->tex[0].img_tex == NULL)
		return (print_error_2(2));
	d->tex[0].ad_tex = mlx_get_data_addr(d->tex[0].img_tex,
			&d->tex[0].bits_text,
			&d->tex[0].length_tex, &d->tex[0].endian_text);
	return (0);
}

int	init_tex_so(t_mlx *d)
{
	d->tex[1].img_tex = mlx_xpm_file_to_image(d->mlx,
			d->so, &d->tex[1].img_width_tex, &d->tex[1].img_height_tex);
	if (d->tex[1].img_tex == NULL)
		return (print_error_2(2));
	d->tex[1].ad_tex = mlx_get_data_addr(d->tex[1].img_tex,
			&d->tex[1].bits_text,
			&d->tex[1].length_tex, &d->tex[1].endian_text);
	return (0);
}

int	init_tex_we(t_mlx *d)
{
	d->tex[2].img_tex = mlx_xpm_file_to_image(d->mlx,
			d->we, &d->tex[2].img_width_tex, &d->tex[2].img_height_tex);
	if (d->tex[2].img_tex == NULL)
		return (print_error_2(2));
	d->tex[2].ad_tex = mlx_get_data_addr(d->tex[2].img_tex,
			&d->tex[2].bits_text,
			&d->tex[2].length_tex, &d->tex[2].endian_text);
	return (0);
}

int	init_tex_ea(t_mlx *d)
{
	d->tex[3].img_tex = mlx_xpm_file_to_image(d->mlx,
			d->ea, &d->tex[3].img_width_tex, &d->tex[3].img_height_tex);
	if (d->tex[3].img_tex == NULL)
		return (print_error_2(2));
	d->tex[3].ad_tex = mlx_get_data_addr(d->tex[3].img_tex,
			&d->tex[3].bits_text,
			&d->tex[3].length_tex, &d->tex[3].endian_text);
	return (0);
}

int	init_tex(t_mlx *d)
{
	if (init_tex_ea(d) == 1)
		return (1);
	if (init_tex_we(d) == 1)
		return (1);
	if (init_tex_so(d) == 1)
		return (1);
	if (init_tex_no(d) == 1)
		return (1);
	return (0);
}
