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

void    tile_size()
{
	int	i;
	int	j;

	i = data.window_width / data.map_width;
	j = data.window_height / data.map_height;
	data.tile_size = i > j ? j * 0.2 : i * 0.2;
}

void    make_map2d()
{
	data.y = 0;
	while (data.world[data.y])
	{
		data.x = 0;
		while (data.world[data.y][data.x])
		{
			data.world[data.y][data.x] == '1' ?
			colored_square(data.tile_size, data.x * data.tile_size, data.y * data.tile_size, get_color(0, 0, 255)) :
			colored_square(data.tile_size, data.x * data.tile_size, data.y * data.tile_size, get_color(0, 0, 0));
			data.x++;
		}
		data.y++;
	}
}