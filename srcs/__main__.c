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
	mlx_hook(g_cube.win_ptr, 2, 0, ft_key_pressed, NULL);
	mlx_hook(g_cube.win_ptr, 3, 0, ft_key_released, NULL);
	mlx_hook(g_cube.win_ptr, 17, 0, exit_game, NULL);
	mlx_loop_hook(g_cube.mlx_ptr, render_, NULL);
	mlx_loop(g_cube.mlx_ptr);
	return (0);
}

int		exit_game()
{
	mlx_destroy_image(g_cube.mlx_ptr, g_img.img);
	mlx_destroy_window(g_cube.mlx_ptr, g_cube.win_ptr);
	exit(0);
	return (0);
}
