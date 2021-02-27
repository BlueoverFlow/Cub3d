/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:22:53 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 03:23:39 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    make_map2d()
{
	int	i;
	int	j;

	get_world();
	i = data->window_width / data->map_width;
	j = data->window_height / data->map_height;
	data->tile_size = i > j ? j : i;
	// if (i > j)
	// 	data->tile_size = j;
	// else
	// 	data->tile_size = i ;
        // data->tile_size *= 0.2;
        data->mapd_w = data->tile_size * data->map_width;
        data->mapd_h = data->tile_size * data->map_height;
	make__map2d();
}

void    make__map2d()
{
	data->y = 0;
	player->pix_y = 0;
	while (data->world[data->y])
	{
		data->x = 0;
		player->pix_x = 0;
		while (data->world[data->y][data->x])
		{
                        data->world[data->y][data->x] == '1' ?
                        colored_square(data->tile_size, player->pix_x, player->pix_y, get_color(0, 0, 255)) :
                        colored_square(data->tile_size, player->pix_x, player->pix_y, get_color(0, 0, 0));
			data->x++;
			player->pix_x += data->tile_size;
		}
		data->y++;
		player->pix_y += data->tile_size;
	}
}

int    find_p()
{
        data->y = 0;
        player->pix_y = 0;
        while (data->world[data->y])
        {
                data->x = 0;
                player->pix_x = 0;
                while (data->world[data->y][data->x])
                {
                        if (data->world[data->y][data->x] == 'N'        ||
                        data->world[data->y][data->x] == 'W'            ||
                        data->world[data->y][data->x] == 'S'            ||
                        data->world[data->y][data->x] == 'E')
                        {
                                init_player();
                                charactere();
                                return (1);
                        }
                        data->x++;
                        player->pix_x += data->tile_size;
                }
                data->y++;
                player->pix_y += data->tile_size;
        }
        return(0);
}

void    init_player()
{
        player->x = (player->pix_x + (data->tile_size / 2));
        player->y = (player->pix_y + (data->tile_size / 2));
        player->move_direction = 0;
        player->move_speed = 2;
        player->rot_speed = radian(10);
        player->side_ang = 0;
        player->direction = 0;
        player->scale = data->tile_size / 4;
}