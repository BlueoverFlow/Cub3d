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

int		supreme_init(int argc, char **argv)
{
	file.argv = argv;
	file.argc = argc;
	var_init();
	check_err();
	get_world();
	find_p();
	g_cube.map.w = g_cube.map_size.x * TILE_SIZE;
	g_cube.map.h = g_cube.map_size.y * TILE_SIZE;
	g_cube.ratio = (float)FOV / (float)g_cube.window.w;
	g_rays = malloc(sizeof(t_ray) * g_cube.window.w);
	texture_init();
	return (1);
}

void 	var_init()
{
	file.file = file.argv[1];
	file.elem = malloc((sizeof(char *) * 8) + 1);
	file.elem[8] = NULL;
	file.map_pos = 1;
	g_cube.map_size.y = 1;
}

int    find_p()
{
	int	p;
	int x;
	int	y;

	p = 0;
	y = 0;
	while (g_cube.map[y])
	{
		x = 0;
		while (g_cube.map[y][x])
		{
			if (charactere(y, x))
				p++;
			x++;
		}
		y++;
    }
	if (p == 0)
		return (out("Error\nNo g_player. found!\n"));
	return (p == 1 ? 1 : out("Error\ntoo many g_player.s!\n"));
}

int    charactere(int y, int x)
{
	if (g_cube.map[y][x] == 'N')
		g_player.rot_ang = radian(270);
	else if (g_cube.map[y][x] == 'W')
		g_player.rot_ang = radian(180);
	else if (g_cube.map[y][x] == 'S')
		g_player.rot_ang = radian(90);
	else if (g_cube.map[y][x] == 'E')
		g_player.rot_ang = radian(0);
	else
		return (0);
	g_player.pos.x = (x * TILE_SIZE + (TILE_SIZE / 2));
	g_player.pos.y = (y * TILE_SIZE + (TILE_SIZE / 2));
	return (1);
}

void	sub_init()
{
	g_cube.mlx_ptr = mlx_init();
	g_cube.win_ptr = mlx_new_window(g_cube.mlx_ptr, g_cube.window.w, g_cube.window.h, GAME_TITLE);
	g_img.img = mlx_new_image(g_cube.mlx_ptr, g_cube.window.w, g_cube.window.h);
	g_img.addr = (int *)mlx_get_data_addr(g_img.img, &g_imgd[1].bits_per_pixel, &g_imgd[1].size_line, &g_imgd[1].endian);
}