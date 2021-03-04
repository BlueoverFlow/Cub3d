/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:33:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 22:19:14 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int     main(int argc, char *argv[])
{
	if (ERROR(supreme_init(argc, argv)))
		return (0);
	make_img();
	sub_init();
	mlx_hook(data->win_ptr, 2, 0, key_pressed, NULL);
    mlx_hook(data->win_ptr, 3, 0 ,key_released, NULL);
	mlx_hook(data->win_ptr, 17, 0, exit_game, NULL);
    mlx_loop_hook(data->mlx_ptr, update, NULL);
	mlx_loop(data->mlx_ptr);
	return (0);
}

void	make_img()
{
	draw->img = mlx_new_image(data->mlx_ptr, data->window_width, data->window_height);
	g_data_3d = (int *)mlx_get_data_addr(draw->img, &draw->bits_per_pixel, &draw->line_length, &draw->endian);
}

int		exit_game()
{
	mlx_destroy_image(data->mlx_ptr, draw->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}