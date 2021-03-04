/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:59:31 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 11:59:34 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int    find_p()
{
	int	p;

	p = 0;
	data.y = 0;
	while (data.world[data.y])
	{
		data.x = 0;
		while (data.world[data.y][data.x])
		{
			if (charactere())
				p++;
			data.x++;
		}
		data.y++;
    }
	if (p == 0)
		return (out("Error\nNo player found!\n"));
	return (p == 1 ? 1 : out("Error\ntoo many players!\n"));
}

int    charactere()
{
	if (data.world[data.y][data.x] == 'N')
			player.rot_ang = radian(270);
	else if (data.world[data.y][data.x] == 'W')
			player.rot_ang = radian(180);
	else if (data.world[data.y][data.x] == 'S')
			player.rot_ang = radian(90);
	else if (data.world[data.y][data.x] == 'E')
			player.rot_ang = radian(0);
	else
		return (0);
	player.x = (data.x * data.tile_size + (data.tile_size / 2));
	player.y = (data.y * data.tile_size + (data.tile_size / 2));
	return (1);
}