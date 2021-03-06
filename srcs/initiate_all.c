/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:33:01 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 23:19:19 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		supreme_init(int argc, char **argv)
{
	file.argv = argv;
	file.argc = argc;
	var_init();
	check_err();
	g_rays = malloc(sizeof(t_ray) * data.window_width + 1);
	data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_width, data.window_height, "Cub3d");
	return (1);
}

void 	var_init()
{
	file.file = file.argv[1];
	file.elem = malloc((sizeof(char *) * 8) + 1);
	file.elem[8] = NULL;
	file.map_pos = 1;
	data.map_height = 1;
}

void    init_player()
{
	player.move_direction = 0;
	player.move_speed = 2;
	player.rot_speed = radian(10);
	player.side_ang = 0;
	player.direction = 0;
}

void	sub_init()
{
	make_img();
	get_world();
	init_player();
	find_p();
	// init_texture();
}

void	init_texture()
{
	g_dnorth = mlx_xpm_file_to_image(data.mlx_ptr, g_texture.north, &g_dimd[0].w, &g_dimd[0].h);
	g_north = (int *)mlx_get_data_addr(g_dnorth, &draw2[2].bits_per_pixel, &draw2[2].line_length, &draw2[2].endian);
	g_dsouth = mlx_xpm_file_to_image(data.mlx_ptr, g_texture.south, &g_dimd[1].w, &g_dimd[1].h);
	g_south = (int *)mlx_get_data_addr(g_dsouth, &draw2[3].bits_per_pixel, &draw2[3].line_length, &draw2[3].endian);
	g_deast = mlx_xpm_file_to_image(data.mlx_ptr, g_texture.east, &g_dimd[2].w, &g_dimd[2].h);
	g_east = (int *)mlx_get_data_addr(g_deast, &draw2[4].bits_per_pixel, &draw2[4].line_length, &draw2[4].endian);
	g_dwest = mlx_xpm_file_to_image(data.mlx_ptr, g_texture.west, &g_dimd[3].w, &g_dimd[3].h);
	g_west = (int *)mlx_get_data_addr(g_dwest, &draw2[5].bits_per_pixel, &draw2[5].line_length, &draw2[5].endian);
	cast_rays();
	cast_walls();
}