/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:33:01 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/03/02 23:19:19 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void			cast_walls(void)
{
	int			i;
	int			j;
	t_wall_data	wall;

	wall.pp_dist = ((float)g_cube.window.w / 2.0F) / tanf(radian((FOV / 2)));
	i = 0;
	while (i < g_cube.window.w)
	{
		wall.corr_len = g_rays[i].length * cosf(g_rays[i].angle - g_player.rot_ang);
		wall.hieght = (float)TILE_SIZE / wall.corr_len * (float)wall.pp_dist;
		wall.top = ((float)g_cube.window.h / 2.0F) - (wall.hieght / 2.0F);
		wall.top = wall.top < 0 ? 0 : wall.top;
		wall.bottom = ((float)g_cube.window.h / 2.0F) + (wall.hieght / 2.0F);
		wall.bottom = wall.bottom > g_cube.window.h ? g_cube.window.h : wall.bottom;
		j = 0;
		while (j < wall.top)
			g_img.addr[(j++ * g_cube.window.w) + i] = get_color(0,255,255);
		j = wall.bottom;
		while (j < g_cube.window.h)
			g_img.addr[(j++ * g_cube.window.w) + i] = get_color(255,0,0);
		draw_wall(wall.top, wall.bottom, wall.hieght, i);
		++i;
	}
	mlx_put_image_to_window(g_cube.mlx_ptr, g_cube.win_ptr, g_img.img, 0, 0);
}

void			draw_wall(int w_top, int w_bottom, int w_height, int index)
{
	int j;
	int offset_x;
	int offset_y;
	int	color;

	if (g_rays[index].hit_ver)
		offset_x = (int)g_rays[index].w_hit.y % TILE_SIZE;
	else
		offset_x = (int)g_rays[index].w_hit.x % TILE_SIZE;
	j = w_top;
	while (j < w_bottom)
	{
		offset_y = (j + ((w_height / 2) - (g_cube.window.h / 2))) *
			((float)g_dimd[0].h / (float)w_height);
		if (g_rays[index].hit_hor && g_rays[index].r_up)
			color = g_north[(offset_y * g_dimd[0].h) + offset_x];
		else if (g_rays[index].hit_hor && g_rays[index].r_down)
			color = g_south[(offset_y * g_dimd[0].h) + offset_x];
		else if (g_rays[index].hit_ver && g_rays[index].r_left)
			color = g_west[(offset_y * g_dimd[0].h) + offset_x];
		else if (g_rays[index].hit_ver && g_rays[index].r_right)
			color = g_east[(offset_y * g_dimd[0].h) + offset_x];
		g_img.addr[(j * g_cube.window.w) + index] = color;
		++j;
	}
}