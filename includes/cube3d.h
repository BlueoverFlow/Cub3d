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
# define INIT_ROT_SPD (g_data.ray_step * 30)
# define GAME_TITLE "Cub3D"


typedef struct	s_axis
{
	float		x;
	float		y;
}				t_axis;

typedef struct	s_dimens
{
	int			w;
	int			h;
}               t_dimens;

typedef struct	s_ray
{
	float		length;
	float		angle;
	int			r_left;
	int			r_right;
	int			r_up;
	int			r_down;
	t_axis		w_hit;
	int			hit_ver;
	int			hit_hor;
}				t_ray;

typedef struct	s_player
{
    t_axis		axis;
    int			turn_direct;
    int			move_direct;
    float		rot_ang;
    float		side_ang;
    float		move_speed;
    float		rot_speed;
}				t_player;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_ray_data
{
	t_axis		hit;
	t_axis		inter;
	t_axis		step;
	float		len;
}				t_ray_data;

typedef struct	s_wall_data
{
	float		top;
	float		bottom;
	float		hieght;
	float		pp_dist;
	float		corr_len;
}				t_wall_data;

typedef struct s_file
{
    char    *file;
    char    **argv;
    int     argc;
    char    **elem;
    int     screenshot;
    int     map_pos;
}           t_file;

typedef struct  s_data
{
	char        **map;
	char		**world;
	t_dimens    dimens;
	t_dimens    m_dimens;
	int         rows;
	int         cols;
	t_color     floor;
	t_color     ciel;
	float       ray_step;
	char        *xpm_n;
	char        *xpm_w;
	char        *xpm_s;
	char        *xpm_e;
	char		*xpm_sprite;
}               t_data;

typedef struct s_image_data
{
	int     bits_per_pixel;
	int     size_line;
	int     endian;
}               t_image_data;

t_image_data    g_imgd[10];
t_dimens        g_dimd[10];
t_player		g_p;
t_data          g_data;
t_ray			*g_rays;
t_file			file;
char			*g_fname;
void			*g_mlx;
void			*g_win;
void			*g_img_3d;
void			*g_img_n;
void			*g_img_s;
void			*g_img_w;
void			*g_img_e;
int				*g_data_3d;
int				*g_data_n;
int				*g_data_s;
int				*g_data_w;
int				*g_data_e;
int				g_is_pressed;

void			ft_init_all();
void			ft_update_all();
void			ft_wall(int wall_top, int wall_bottom, int wall_height, int index);
void			ft_rays(float x, float y, float angle);
void			ft_draw_walls();
int				ft_update();
int				ft_key_pressed(int key);
int				ft_key_released(int key);
unsigned int	ft_color_s(t_color color);
int				ft_is_wall(float x, float y);
float			radian(float angle);
float       	distanceAB(float Ax, float Ay);
float      		norm_angle(float angle);
void            ft_process_line(char *line);
void            ft_read_all(int fd);
char            *ft_strnstr(const char *haystack, const char *needle, size_t len);
char            *ft_strdup(const char *s);
char            **ft_split(const char *ss, char c);
int             ft_atoi(const char *str);
int				supreme_init(int argc, char **argv);
void 			var_init();
int				check_err();
int				check_elements();
int				check_filename(char *ext);
int				check_args();
char			**find_id(char	*id);
int				handle_r();
int				handle_map();
int				map_parsing(int k, int j);
int				texture_data();
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen_2d(char **str);
int				out(char *error_msg);
int				free_2d(char **str);
void			read_file();
void			read_elements();
void			the9th_elem(char *line, int fd);
void			read_map();
void			get_mapwidth();
void			get_world();
void			*ft_calloc(size_t count, size_t size);
int				ft_strnchar(const char *str, char c);
unsigned int	get_color(int r, int g, int b);
int				exit_game();
int				find_p();
int				charactere(int y, int x);



#endif