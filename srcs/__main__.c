/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __main__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:39:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/02 22:10:14 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int main(int argc, char **argv)
{
	supreme_init(argc, argv);
	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, g_data.dimens.w, g_data.dimens.h, GAME_TITLE);
	g_img_3d = mlx_new_image(g_mlx, g_data.dimens.w, g_data.dimens.h);
	g_data_3d = (int *)mlx_get_data_addr(g_img_3d, &g_imgd[1].bits_per_pixel, &g_imgd[1].size_line, &g_imgd[1].endian);
	ft_init_all();
	mlx_hook(g_win, 2, 0, ft_key_pressed, NULL);
	mlx_hook(g_win, 3, 0, ft_key_released, NULL);
	mlx_hook(g_win, 17, 0, exit_game, NULL);
	mlx_loop_hook(g_mlx, ft_update, NULL);
	mlx_loop(g_mlx);
	return (0);
}

int		exit_game()
{
	mlx_destroy_image(g_mlx, g_img_3d);
	mlx_destroy_window(g_mlx, g_win);
	exit(0);
	return (0);
}
