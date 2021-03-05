/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:10:24 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 03:25:09 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# define FOV 60
# define TILE_SIZE 400
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define PI 6.28310000

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
    int     window_width;
    int     window_height;
    int     map_width;
    int     map_height;
    int     mapd_w;
    int     mapd_h;
    char    **map;
    char    **world;
    void    *win_ptr;
    void    *mlx_ptr;
    int     tile_size;
    int     x;
    int     y;
}           t_cube;

typedef struct  s_axis
{
    float       x;
    float       y;
}               t_axis;

typedef struct          s_player
{
    float               x;
    float               y;
    int                 pix_x;
    int                 pix_y;
    float               scale;
    float               ang;
    int                 move_direction;
    float               rot_ang;
    float               side_ang;
    float               direction;
    float               move_speed;
    float               rot_speed;
}                       t_player;

typedef struct s_grides
{
    t_axis      hit;
    t_axis      intercept;
    t_axis      step;
    float       len;
}               t_grides;         

typedef struct  s_ray
{
    float   length;
    float   ang;
    int     f_left;
    int     f_right;
    int     f_down;
    int     f_up;
    t_axis  w_hit;
    int     hit_ver;
    int     hit_hor;
}               t_ray;

typedef struct  s_wall
{
    float   top;
    float   bottom;
    float   height;
    float   distance;
    float   corr_len;
}               t_wall;

typedef struct s_image
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}           t_image;

typedef struct s_image2
{
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}           t_image2;

typedef struct  s_dimens
{
    int         w;
    int         h;
}               t_dimens;

typedef struct  s_texture
{
	char		*north;
	char		*west;
	char        *south;
	char        *east;
	char        **map;
	t_dimens    dimens;
	t_dimens    m_dimens;
	int         rows;
	int         cols;
	char        *xpm_sprite;
}               t_texture;

//======================= main.c ==================
int     main(int argc, char *argv[]);
void	make_img();
int		exit_game();
int     supreme_init(int argc, char **argv);

//======================= initiate_all.c ==================
int		supreme_init(int argc, char **argv);
void 	var_init();
void	sub_init();

//============== error_management.c ===============
int     check_err();
int     check_filename(char *ext);
int     check_args();
int		check_elements();
void	init_texture();

//======================= utils.c =================
void			colored_square(int scale, int x, int y, int color);
unsigned int	get_color(int r, int g, int b);
void			print_circle(int x, int y, int r, int color);
float			radian(float angle);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
float			norm_angle(float angle);
void			draw_line(int l, int x, int y, float ang, int color);
int				theres_wall(float x, float y);
float			distanceAB(float Ax, float Ay);
int				out(char *error_msg);
int				free_2d(char **str);
int				ft_strlen_2d(char **str);
int				ft_strnchar(const char *str, char c);


//======================= file_management.c =======
void	read_file();
void	read_elements();
void	the9th_elem(char *line, int fd);
void	read_map();

//======================= file_management2.c ======
void	get_mapwidth();
void	get_world();

//======================= elements_handling.c ======
int		handle_r();
char	**find_id(char	*id);
int		handle_map();
char    is_border(int k, int j);
int		map_parsing(int k, int j);
int		texture_data();

//======================= map2d.c ================= 
void    tile_size();
void    make_map2d();
void    init_player();
int     find_p();

//======================= Player.c ================
int    find_p();
int    charactere();

//======================= rays.c ==================
static t_grides     ver_intercept(t_ray *rays);
void                cast_rays();
static void         longer_len(t_ray *rays);
static t_grides     hor_intercept(t_ray *rays);
void static         rays_init(t_ray *rays);

//======================= walls.c ==================
void    cast_walls();
void    ft_wall(int w_top, int w_bottom, int w_height, int index);

//======================= game.c ===================
void    move_player();
int     key_pressed(int key);
int		key_released(int key);
int		update();





t_cube          data;
t_player        player;
t_file          file;
t_image         draw;
t_image2		draw2[10];
t_texture		g_texture;
t_dimens        g_dimd[10];
t_ray           *g_rays;
void            *g_main_img;
void    		*g_img;
int             *g_main_addr;
int             *g_north;
int             *g_south;
int             *g_west;
int             *g_east;
void            *g_dnorth;
void            *g_dsouth;
void            *g_dwest;
void            *g_deast;

#endif
