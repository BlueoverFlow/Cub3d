/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:33:01 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/02/18 23:19:19 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void 	var_init()
{
	g_file.file = g_file.argv[1];
	g_file.elem = malloc((sizeof(char *) * 8) + 1);
	g_file.elem[8] = NULL;
	g_file.map_pos = 1;
	g_cube.rows = 1;
}

static void	sub_init()
{
	g_cube.mlx_ptr = mlx_init();
	g_cube.win_ptr = mlx_new_window(g_cube.mlx_ptr, g_cube.dimens.w, g_cube.dimens.h, GAME_header);
	g_img[0].img = mlx_new_image(g_cube.mlx_ptr, g_cube.dimens.w, g_cube.dimens.h);
	g_img[0].addr = (int *)mlx_get_data_addr(g_img[0].img, &g_img[0].bits_per_pixel, &g_img[0].line_lenght, &g_img[0].endian);
	player_init();
	texture_walls();
	take_screenshot();
}

int		supreme_init(int argc, char **argv)
{
	g_file.argv = argv;
	g_file.argc = argc;
	var_init();
	check_err();
	get_world();
	find_p();
	g_cube.map_size.w = g_cube.cols * TILE_SIZE;
	g_cube.map_size.h = g_cube.rows * TILE_SIZE;
	g_cube.ratio = (float)FOV / (float)g_cube.dimens.w;
	g_rays = malloc(sizeof(t_ray) * g_cube.dimens.w);
	sub_init();
	return (1);
}

void	player_init()
{
	g_player.turn_direct = 0;
	g_player.move_direct = 0;
	g_player.move_speed = (float)INIT_MOVE_SPD;
	g_player.rot_speed = radian((float)INIT_ROT_SPD);
	g_player.side_ang = radian(0);
}