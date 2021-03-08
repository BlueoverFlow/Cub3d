/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:42:21 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/22 17:23:59 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# define RATIO 10
# define TILE_SIZE 400
# define FOV 60
# define INIT_MOVE_SPD ((float)TILE_SIZE / (float)10)
# define INIT_ROT_SPD (g_cube.ratio * 30)
# define GAME_TITLE "Cub3D"

typedef struct	s_dim
{
	int			w;
	int			h;
	float		x;
	float		y;
}               t_dim;

typedef struct	s_ray
{
	float		length;
	float		angle;
	int			r_left;
	int			r_right;
	int			r_up;
	int			r_down;
	t_dim		w_hit;
	int			hit_ver;
	int			hit_hor;
}				t_ray;

typedef struct	s_player
{
    t_dim		pos;
    int			turn_direct;
    int			move_direct;
    float		rot_ang;
    float		side_ang;
    float		move_speed;
    float		rot_speed;
}				t_player;

typedef struct	s_grides
{
	t_dim		hit;
	t_dim		inter;
	t_dim		step;
	float		len;
}				t_grides;

typedef struct	s_wall
{
	float		top;
	float		bottom;
	float		hieght;
	float		pp_dist;
	float		corr_len;
}				t_wall;

typedef struct s_file
{
    char    *file;
    char    **argv;
    int     argc;
    char    **elem;
    int     screenshot;
    int     map_pos;
}           t_file;

typedef struct  s_cube
{
	t_dim    	dimens;
	t_dim    	map_size;
	char        **map;
	char		**world;
	int         rows;
	int         cols;
	float       ratio;
}               t_cube;

typedef struct 	s_texture
{
	char		*north;
	char		*west;
	char		*east;
	char		*south;
}				t_texture;

typedef struct s_image
{
	void	*img;
	int		*addr;
	int     bits_per_pixel;
	int     line_lenght;
	int     endian;
}               t_image;

t_player		g_player;
t_cube          g_cube;
t_ray			*g_rays;
t_file			file;
t_texture		g_texture;
t_image			g_img[5];
t_dim        	g_dim[4];
char			*g_fname;
void			*g_mlx;
void			*g_win;
void			*g_draw_n;
void			*g_draw_s;
void			*g_draw_w;
void			*g_draw_e;
int				*g_north;
int				*g_south;
int				*g_west;
int				*g_east;

void				texture_walls();
void				cast_rays();
void				cast_walls();
int					render_();
void				player_init();
int					ft_key_pressed(int key);
int					ft_key_released(int key);
int					theres_wall(float x, float y);
float				radian(float angle);
float			 	distanceAB(float Ax, float Ay);
float				norm_angle(float angle);
int					supreme_init(int argc, char **argv);
int					check_err();
int					handle_r();
int					handle_map();
int					texture_data();
int					out(char *error_msg);
void				read_file();
void				read_map();
void				move_player();
int					find_p();
void				get_world();
unsigned int		get_color(int r, int g, int b);

#endif