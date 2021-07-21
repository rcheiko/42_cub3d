/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:42:53 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/22 11:48:16 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 500

typedef struct s_tex
{
	int		img_width_tex;
	int		img_height_tex;
	void	*img_tex;
	char	*ad_tex;
	int		length_tex;
	int		bits_text;
	int		endian_text;
}				t_tex;

typedef struct s_sprr
{
	int		img_width_spr;
	int		img_height_spr;
	void	*img_spr;
	char	*ad_spr;
	int		length_spr;
	int		bits_spr;
	int		endian_spr;
}				t_sprr;

typedef struct s_spr
{
	int		x;
	int		y;
	double	dist;
}				t_spr;

typedef struct s_mlx
{
	int		x;
	int		y;
	int		k;
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
	double	val_pi_map;
	void	*mlx;
	void	*window;
	void	*img;
	double	pos_x;
	double	pos_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		keyw;
	int		keys;
	int		keya;
	int		keyd;
	int		keyesc;
	int		keyfg;
	int		keyfd;
	char	*addr;
	double	h_inter_x;
	double	h_inter_y;
	double	v_inter_x;
	double	v_inter_y;
	double	angle;
	double	val_pi;
	double	valeur;
	double	camera_h;
	double	camera_v;
	double	wall_height;
	double	top_pos;
	double	dist_plan;
	double	p_x;
	double	largeur;
	double	longueur;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		**map;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceil_r;
	int		ceil_g;
	int		ceil_b;
	int		i_malloc;
	int		i_map;
	int		row_x;
	int		col_y;
	int		x_perso;
	int		y_perso;
	char	perso;
	double	ray;
	double	angle_tmp;
	double	dist;
	int		p_y;
	double	hor;
	double	ver;
	double	p_y_y;
	int		color_tex;
	int		spr_total;
	double	spr_height;
	double	spr_angle;
	double	spr_dif_ang;
	double	*ray_wall;
	t_tex	tex[4];
	t_spr	*spr;
	t_sprr	*sprr;
	double	x_tmp;
	int		i;
	int		save;
	int		*x_map;
}			t_mlx;

void	init_struct(t_mlx *d);
void	init_struct_2(t_mlx *d);
void	init_struct_map(t_mlx *d);
void	init_struct_mini_map(t_mlx *d);
void	init_all(t_mlx *d);
void	verif_angle(t_mlx *d);
void	my_mlx_pixel_put(t_mlx *d, int x, int y, int color);
void	convertdeg(t_mlx *d);
double	degtorad(double angle, double result);
int		keyhook(t_mlx *d);
int		keypress(int keycode, t_mlx *d);
int		keyrelease(int keycode, t_mlx *d);
int		key_exit(t_mlx *d);
void	movement_w(t_mlx *d);
void	movement_s(t_mlx *d);
void	movement_a(t_mlx *d);
void	movement_d(t_mlx *d);
void	movement_fl_esc(t_mlx *d);
void	affcarre(t_mlx *d, int a);
void	affmap(t_mlx *d);
void	taille_mini_map(t_mlx *d);
void	haut_gauche(t_mlx *d);
void	haut_gauche_calc(t_mlx *d);
void	haut_gauche_2(t_mlx *d);
void	haut_droite(t_mlx *d);
void	haut_droite_calc(t_mlx *d);
void	haut_droite_2(t_mlx *d);
void	bas_droite(t_mlx *d);
void	bas_droite_calc(t_mlx *d);
void	bas_droite_2(t_mlx *d);
void	bas_gauche(t_mlx *d);
void	bas_gauche_calc(t_mlx *d);
void	wall_height(t_mlx *d);
void	draw_walls(t_mlx *d);
void	draw_walls_2(t_mlx *d);
void	draw_walls_3(t_mlx *d);
void	draw_walls_4(t_mlx *d);
void	draw_all(t_mlx *d);
void	angle(t_mlx *d);
void	sprite_init(t_mlx *d);
void	sprite_init_2(t_mlx *d, double dist_spr);
int		aff_perso(t_mlx *d);
int		init_parsing(t_mlx *d, int fd, char **av);
double	calc_sprite(t_mlx *d);
int		init_tex_spr(t_mlx *d);
int		init_tex_no(t_mlx *d);
int		init_tex_so(t_mlx *d);
int		init_tex_we(t_mlx *d);
int		init_tex_ea(t_mlx *d);
int		init_tex(t_mlx *d);
int		my_mlx_texture_put(t_mlx *d, int x, int y, int i);
int		rgb_convert(int r, int g, int b);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
int		is_newline(char *str, char c);
char	*creat_line(char *str, char *buffer);
int		get_rest(char **line, char *str);
int		get_next_line(int fd, char **line);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
int		verif_digit(char *str);
int		print_error(int error);
int		ft_isdigit(int c);
int		ft_strlen_int(int *str);
size_t	ft_strlen_mal(const char *str);
int		print_error_2(int error);
int		del_perso(t_mlx *d);
void	init_struct_map(t_mlx *d);
int		pick_resolution(t_mlx *d, char *str);
int		pick_north(t_mlx *d, char *str);
int		pick_south(t_mlx *d, char *str);
int		pick_west(t_mlx *d, char *str);
int		pick_east(t_mlx *d, char *str);
int		pick_sprite(t_mlx *d, char *str);
int		pick_floor(t_mlx *d, char *str);
int		verif_floor(t_mlx *d);
int		pick_ceil(t_mlx *d, char *str);
int		verif_ceil(t_mlx *d);
int		traitement(t_mlx *d, char *str);
int		traitement_total(t_mlx *d, int fd);
int		find_malloc(t_mlx *d, int fd);
int		fin_malloc(t_mlx *d, int fd);
int		cond_fill_map(t_mlx *d, char *str, int i, int j);
int		fill_map(t_mlx *d, int fd);
int		get_i_map(t_mlx *d, char **av);
int		compar_max(t_mlx *d, int l);
int		ft_malloc_map(t_mlx *d, int j);
int		zero_map(t_mlx *d, int y, int x);
int		check_map(t_mlx *d);
int		check_charset(int val, char *check);
void	angle_character(t_mlx *d);
int		fct_mal_spr(t_mlx *d);
int		malloc_spr(t_mlx *d);
void	fill_spr(t_mlx *d);
void	sort_tab(t_mlx *d);
void	sprite_height(t_mlx *d);
void	draw_sprite(t_mlx *d);
int		init_spr(t_mlx *d);
int		my_mlx_sprite_put(t_mlx *d, int x, int y, int i);
void	draw_all_sprite(t_mlx *d);
void	file_header(t_mlx *d, int fd);
void	screenshot_header(t_mlx *d, int fd, int z);
int		screenshot_init(t_mlx *d);
void	screenshot_color(t_mlx *d, int fd);
int		my_mlx_pixel_pick(t_mlx *d, int x, int y);
void	barre_de_vie(t_mlx *d);
void	barre_de_vie_2(t_mlx *d);
void	barre_de_vie_3(t_mlx *d);
void	free_all(t_mlx *d);
void	free_ceil(char **rgb, char **result);
void	free_floor(char **rgb, char **result);
void	free_position(char **result);
void	free_resolution(char **result);
char	*free_protected(char *str);
#endif
