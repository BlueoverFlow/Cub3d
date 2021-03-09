/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:12:25 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/22 17:25:04 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static int		create_bmp()
{
	g_file.bits_perpixel = 24;
	g_file.row_bytes = (unsigned int)(((g_file.bits_perpixel
						* (unsigned int)g_cube.dimens.w + 31) / 32) * 4);
	g_file.image_size = g_file.row_bytes * g_cube.dimens.h;
	g_file.pixel_data_offset = 54;
	g_file.header_size = 40;
	g_file.size = 54 + g_file.image_size;
	g_file.planes = 1;
	ft_bzero(g_file.header, 54);
	ft_memcpy(g_file.header, &"BM", 2);
	ft_memcpy(g_file.header + 2, &g_file.size, 4);
	ft_memcpy(g_file.header + 10, &g_file.pixel_data_offset, 4);
	ft_memcpy(g_file.header + 14, &g_file.header_size, 4);
	ft_memcpy(g_file.header + 18, &g_cube.dimens.w, 4);
	ft_memcpy(g_file.header + 22, &g_cube.dimens.h, 4);
	ft_memcpy(g_file.header + 26, &g_file.planes, 2);
	ft_memcpy(g_file.header + 28, &g_file.bits_perpixel, 2);
	ft_memcpy(g_file.header + 34, &g_file.image_size, 4);
	g_file.screen = malloc(g_file.image_size);
	return (0);
}

static void	save_bmp()
{
	int	fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
	if (fd == -1)
		return ;
	write(fd, g_file.header, 54);
	write(fd, g_file.screen, g_file.image_size);
	close(fd);
	free(g_file.screen);
}

void	take_screenshot()
{
	// int		new_y;
	// int		index;

	if (g_file.screenshot == 1)
	{
		create_bmp();
		cast_rays();
		cast_walls();
		// new_y = g_cube.dimens.h - (g_player.pos.y + 1);
		// index = new_y * g_file.row_bytes + g_player.pos.x * 3;
		// // g_file.screen[index + 0] = data-rgb.b;
		// // g_file.screen[index + 1] = data-rgb.g;
		// // g_file.screen[index + 2] = data-rgb.r;
		save_bmp();
		exit(0);
	}
}

// t_color		color_hex_to_rgb(unsigned int color)
// {
// 	t_color		out_clr;

// 	out_clr.r = color / POW(256);
// 	out_clr.g = (color - (out_clr.r * POW(256))) / 256;
// 	out_clr.b = color - (out_clr.r * POW(256) + out_clr.g * 256);
// 	return (out_clr);
// }

// int		create_bmp(t_data *data)
// {
// 	unsigned int width;
// 	unsigned int height;

// 	width = data->res_x;
// 	height = data->res_y;
// 	data->bmp.bits_ppixel = 24;
// 	data->bmp.row_bytes = (unsigned int)(((data->bmp.bits_ppixel
// 						* (unsigned int)data->res_x + 31) / 32) * 4);
// 	data->bmp.image_size = data->bmp.row_bytes * data->res_y;
// 	data->bmp.pixel_data_offset = 54;
// 	data->bmp.header_size = 40;
// 	data->bmp.file_size = 54 + data->bmp.image_size;
// 	data->bmp.planes = 1;
// 	ft_bzero(data->bmp.header, 54);
// 	ft_memcpy(data->bmp.header, &"BM", 2);
// 	ft_memcpy(data->bmp.header + 2, &data->bmp.file_size, 4);
// 	ft_memcpy(data->bmp.header + 10, &data->bmp.pixel_data_offset, 4);
// 	ft_memcpy(data->bmp.header + 14, &data->bmp.header_size, 4);
// 	ft_memcpy(data->bmp.header + 18, &width, 4);
// 	ft_memcpy(data->bmp.header + 22, &height, 4);
// 	ft_memcpy(data->bmp.header + 26, &data->bmp.planes, 2);
// 	ft_memcpy(data->bmp.header + 28, &data->bmp.bits_ppixel, 2);
// 	ft_memcpy(data->bmp.header + 34, &data->bmp.image_size, 4);
// 	data->bmp.buffer = malloc(data->bmp.image_size);
// 	return (0);
// }

// void	save_bmp(t_data *data)
// {
// 	int	fd;

// 	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
// 	if (fd == -1)
// 		return ;
// 	write(fd, data->bmp.header, 54);
// 	write(fd, data->bmp.buffer, data->bmp.image_size);
// 	close(fd);
// 	free(data->bmp.buffer);
// }