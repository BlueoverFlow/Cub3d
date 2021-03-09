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
# define GAME_header "Cub3D"

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
	float		distance;
	float		corr_len;
	float		height;
}				t_wall;

typedef struct s_file
{
    char    		*file;
    char    		**argv;
    int     		argc;
    char    		**elem;
    int				screenshot;
	unsigned int	bits_perpixel;
    int     		map_pos;
	unsigned char	*screen;
	unsigned char	header[54];
	unsigned int	size;
	unsigned char	planes;
	unsigned int	pixel_data_offset;
	unsigned int	header_size;
	unsigned int	image_size;
	int	row_bytes;

}           t_file;

typedef struct	s_bmp
{
	unsigned char	*buffer;
	unsigned char	header[54];
	unsigned char	planes;
	unsigned int	file_size;
	unsigned int	pixel_data_offset;
	unsigned int	header_size;
	unsigned int	bits_ppixel;
	unsigned int	image_size;
	int				row_bytes;
}				t_bmp;

typedef struct  s_cube
{
	t_dim    	dimens;
	t_dim    	map_size;
	t_dim		dim;
	void		*mlx_ptr;
	void		*win_ptr;
	char        **map;
	char		**world;
	int         rows;
	int         cols;
	int			floor[4];
	int			ceilling[4];
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

typedef struct sprite
{
	int	n_sprite;
}				t_sprite;

t_player		g_player;
t_cube          g_cube;
t_ray			*g_rays;
t_file			g_file;
t_texture		g_texture;
t_image			g_img[5];
t_dim        	g_dim[4];
t_sprite		g_sprite;
char			*g_fname;
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
char				**find_id(char	*id);
int					handle_F_C();
int					exit_game();
void				take_screenshot();

#endif