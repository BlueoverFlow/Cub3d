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

int		supreme_init(int argc, char **argv)
{
	data = malloc(sizeof(t_cube));
	player = malloc(sizeof(t_player));
	draw = malloc(sizeof(t_image));
	file = malloc(sizeof(t_file));
	file->argv = argv;
	file->argc = argc;
	var_init();
	if (ERROR(check_err()))
		return (0);
	g_rays = malloc(sizeof(t_ray) * data->window_width + 1);
	data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width, data->window_height, "Cub3d");
	return (1);
}

void 	var_init()
{
	file->file = file->argv[1];
	file->elem = malloc((sizeof(char *) * 8) + 1);
	file->elem[8] = NULL;
	file->map_pos = 1;
	data->map_height = 1;
}
