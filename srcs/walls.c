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

void			texture_walls()
{
	g_draw_n = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.north, &g_dim[0].w, &g_dim[0].h);
	g_north = (int *)mlx_get_data_addr(g_draw_n, &g_img[1].bits_per_pixel, &g_img[1].line_lenght, &g_img[1].endian);
	g_draw_s = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.south,  &g_dim[1].w, &g_dim[1].h);
	g_south = (int *)mlx_get_data_addr(g_draw_s, &g_img[2].bits_per_pixel, &g_img[2].line_lenght, &g_img[2].endian);
	g_draw_w = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.west, &g_dim[2].w, &g_dim[2].h);
	g_west = (int *)mlx_get_data_addr(g_draw_w, &g_img[3].bits_per_pixel, &g_img[3].line_lenght, &g_img[3].endian);
	g_draw_e = mlx_xpm_file_to_image(g_cube.mlx_ptr, g_texture.east,  &g_dim[3].w, &g_dim[3].h);
	g_east = (int *)mlx_get_data_addr(g_draw_e, &g_img[4].bits_per_pixel, &g_img[4].line_lenght, &g_img[4].endian);
	cast_rays();
	cast_walls();
}

static	void			draw_wall(int w_top, int w_bottom, int w_height, int index)
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
		offset_y = (j + ((w_height / 2) - (g_cube.dimens.h / 2))) *
			((float)g_dim[0].h / (float)w_height);
		if (g_rays[index].hit_hor && g_rays[index].r_up)
			color = g_north[(offset_y * g_dim[0].h) + offset_x];
		else if (g_rays[index].hit_hor && g_rays[index].r_down)
			color = g_south[(offset_y * g_dim[0].h) + offset_x];
		else if (g_rays[index].hit_ver && g_rays[index].r_left)
			color = g_west[(offset_y * g_dim[0].h) + offset_x];
		else if (g_rays[index].hit_ver && g_rays[index].r_right)
			color = g_east[(offset_y * g_dim[0].h) + offset_x];
		g_img[0].addr[(j * g_cube.dimens.w) + index] = color;
		++j;
	}
}

// void	draw_vertical_line1(t_data *data, int x, int i, int end)
// {
// 	while (++i < end)
// 		my_pixel_put(data, x, i, data->c);
// }

// void	draw_vertical_line2(t_data *data, int x, int i, int end)
// {
// 	while (++i < end)
// 		my_pixel_put(data, x, i, data->f);
// }

void			cast_walls()
{
	int			i;
	int			j;
	t_wall	wall;

	wall.distance = ((float)g_cube.dimens.w / 2.0F) / tanf(radian((FOV / 2)));
	i = 0;
	while (i < g_cube.dimens.w)
	{
		wall.corr_len = g_rays[i].length * cosf(g_rays[i].angle - g_player.rot_ang);
		wall.height = (float)TILE_SIZE / wall.corr_len * (float)wall.distance;
		wall.top = ((float)g_cube.dimens.h / 2.0F) - (wall.height / 2.0F);
		wall.top = wall.top < 0 ? 0 : wall.top;
		wall.bottom = ((float)g_cube.dimens.h / 2.0F) + (wall.height / 2.0F);
		wall.bottom = wall.bottom > g_cube.dimens.h ? g_cube.dimens.h : wall.bottom;
		j = 0;
		while (j < wall.top)
			g_img[0].addr[(j++ * g_cube.dimens.w) + i] = get_color(g_cube.floor[0],g_cube.floor[1],g_cube.floor[2]);
		j = wall.bottom;
		while (j < g_cube.dimens.h)
			g_img[0].addr[(j++ * g_cube.dimens.w) + i] = get_color(g_cube.ceilling[0],g_cube.ceilling[1],g_cube.ceilling[2]);
		draw_wall(wall.top, wall.bottom, wall.height, i);
		++i;
	}
	mlx_put_image_to_window(g_cube.mlx_ptr, g_cube.win_ptr, g_img[0].img, 0, 0);
}