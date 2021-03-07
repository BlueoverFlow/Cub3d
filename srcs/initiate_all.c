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
	g_data.m_dimens.w = g_data.cols * TILE_SIZE;
	g_data.m_dimens.h = g_data.rows * TILE_SIZE;
	g_data.ray_step = (float)FOV / (float)g_data.dimens.w;
	g_rays = malloc(sizeof(t_ray) * g_data.dimens.w);
	return (1);
}

void 	var_init()
{
	file.file = file.argv[1];
	file.elem = malloc((sizeof(char *) * 8) + 1);
	file.elem[8] = NULL;
	file.map_pos = 1;
	g_data.rows = 1;
}

int    find_p()
{
	int	p;
	int x;
	int	y;

	p = 0;
	y = 0;
	while (g_data.map[y])
	{
		x = 0;
		while (g_data.map[y][x])
		{
			if (charactere(y, x))
				p++;
			x++;
		}
		y++;
    }
	if (p == 0)
		return (out("Error\nNo player found!\n"));
	return (p == 1 ? 1 : out("Error\ntoo many players!\n"));
}

int    charactere(int y, int x)
{
	if (g_data.map[y][x] == 'N')
		g_p.rot_ang = radian(270);
	else if (g_data.map[y][x] == 'W')
		g_p.rot_ang = radian(180);
	else if (g_data.map[y][x] == 'S')
		g_p.rot_ang = radian(90);
	else if (g_data.map[y][x] == 'E')
		g_p.rot_ang = radian(0);
	else
		return (0);
	g_p.axis.x = (x * TILE_SIZE + (TILE_SIZE / 2));
	g_p.axis.y = (y * TILE_SIZE + (TILE_SIZE / 2));
	return (1);
}