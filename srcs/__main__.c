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

static	int		exit_game()
{
	mlx_destroy_image(g_mlx, g_img[0].img);
	mlx_destroy_window(g_mlx, g_win);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	supreme_init(argc, argv);
	mlx_hook(g_win, 2, 0, ft_key_pressed, NULL);
	mlx_hook(g_win, 3, 0, ft_key_released, NULL);
	mlx_hook(g_win, 17, 0, exit_game, NULL);
	mlx_loop_hook(g_mlx, render_, NULL);
	mlx_loop(g_mlx);
	return (0);
}