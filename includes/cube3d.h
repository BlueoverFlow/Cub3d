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

typedef struct  s_ray
{
    float   length;
    float   ang;
    int     f_left;
    int     f_right;
    int     f_down;
    int     f_up;
    t_dim   w_hit;
    int     hit_ver;
    int     hit_hor;
}               t_ray;

typedef struct s_grides
{
    t_dim      hit;
    t_dim      intercept;
    t_dim      step;
    float       len;
}               t_grides;

typedef struct  s_wall
{
    float   top;
    float   bottom;
    float   height;
    float   distance;
    float   corr_len;
}               t_wall;

typedef struct s_file
{
    char    *file;
    char    **argv;
    int     argc;
    char    **elem;
    int     screenshot;
    int     map_pos;
}           t_file;

typedef struct s_cube
{
	t_dim	window;
	t_dim	map_size;
	t_dim	map;
	float	ratio;
    char    **map;
    char    **world;
    void    *win_ptr;
    void    *mlx_ptr;
}           t_cube;

typedef struct	s_player
{
	t_dim		pos;
    float		ang;
    int			move_directionion;
    float		rot_ang;
    float		side_ang;
    float     	direction;
    float		move_speed;
    float		rot_speed;
	int			is_pressed;
}				t_player;

typedef struct	s_texture
{
	char		*north;
	char		*west;
	char		*east;
	char		*south;
}				t_texture;

typedef struct s_image
{
	int     bits_per_pixel;
	int     line_lenght;
	int     endian;
	void	*img;
	int		*addr;
}               t_image;

t_image			g_img;
t_player		g_p;
t_texture		g_texture;
t_cube			g_cube;
t_ray			*g_rays;
t_file			file;
t_dim			g_dimd[10];
t_image			g_imgd[10];
char			*g_fname;
void			*g_cube.mlx_ptr;
void			*g_cube.win_ptr;
void			*g_draw_n;
void			*g_draw_s;
void			*g_draw_w;
void			*g_draw_e;
int				*g_north;
int				*g_south;
int				*g_west;
int				*g_east;

void			sub_init();
int				render();
void			draw_wall(int wall_top, int wall_bottom, int wall_height, int index);
void			cast_rays(float x, float y, float angle);
void			cast_walls();
int				ft_key_pressed(int key);
int				ft_key_released(int key);
int				is_wall(float x, float y);
float			radian(float angle);
float       	distanceAB(float Ax, float Ay);
float      		norm_angle(float angle);
int				supreme_init(int argc, char **argv);
void 			var_init();
void            texture_init();
void            player_init();
int				check_err();
int				check_elements();
int				check_filename(char *ext);
int				check_args();
char			**find_id(char	*id);
int				handle_r();
int				handle_map();
int				map_parsing(int k, int j);
int				texture_data();
int				out(char *error_msg);
void			read_file();
void			read_elements();
void			the9th_elem(char *line, int fd);
void			read_map();
void			get_mapsize();
void			get_world();
unsigned int	get_color(int r, int g, int b);
int				exit_game();
int				find_p();
int				charactere(int y, int x);

#endif