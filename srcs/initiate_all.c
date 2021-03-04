/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:33:01 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 23:19:19 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		supreme_init(int argc, char **argv)
{
	file.argv = argv;
	file.argc = argc;
	var_init();
	check_err();
	g_rays = malloc(sizeof(t_ray) * data.window_width + 1);
	data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_width, data.window_height, "Cub3d");
	return (1);
}

void 	var_init()
{
	file.file = file.argv[1];
	file.elem = malloc((sizeof(char *) * 8) + 1);
	file.elem[8] = NULL;
	file.map_pos = 1;
	data.map_height = 1;
}

void    init_player()
{
	player.move_direction = 0;
	player.move_speed = 2;
	player.rot_speed = radian(10);
	player.side_ang = 0;
	player.direction = 0;
	player.scale = data.tile_size / 4;
}

void	sub_init()
{
	get_world();
	tile_size();
	make_img();
	init_player();
	find_p();
}