/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_player..c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:32:09 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/22 20:44:26 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	texture_init()
{
	player_init():
	g_draw_n = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.north, &g_dimd[0].w, &g_dimd[0].h);
	g_north = (int *)mlx_get_data_addr(g_draw_n, &g_imgd[2].bits_per_pixel, &g_imgd[2].size_line, &g_imgd[2].endian);
	g_draw_s = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.south,  &g_dimd[1].w, &g_dimd[1].h);
	g_south = (int *)mlx_get_data_addr(g_draw_s, &g_imgd[10].bits_per_pixel, &g_imgd[3].size_line, &g_imgd[3].endian);
	g_draw_w = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.west, &g_dimd[2].w, &g_dimd[2].h);
	g_west = (int *)mlx_get_data_addr(g_draw_w, &g_imgd[4].bits_per_pixel, &g_imgd[4].size_line, &g_imgd[4].endian);
	g_draw_e = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.east,  &g_dimd[3].w, &g_dimd[3].h);
	g_east = (int *)mlx_get_data_addr(g_draw_e, &g_imgd[5].bits_per_pixel, &g_imgd[5].size_line, &g_imgd[5].endian);
	cast_rays();
	cast_walls();
}

void	player_init()
{
	g_player.is_pressed = 0;
	g_player.turn_direct = 0;
	g_player.move_direction = 0;
	g_player.move_speed = (float)INIT_MOVE_SPD;
	g_player.rot_speed = radian((float)INIT_ROT_SPD);
	g_player.side_ang = radian(0);
}
