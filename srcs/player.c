/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:32:09 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/22 20:44:26 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		move_player()
{
	t_dim	next;

	next.x = g_player.pos.x + g_player.move_speed * g_player.move_direct * cosf(g_player.rot_ang + g_player.side_ang);
	next.y = g_player.pos.y + g_player.move_speed * g_player.move_direct * sinf(g_player.rot_ang + g_player.side_ang);
	g_player.rot_ang = norm_angle((g_player.rot_ang + g_player.rot_speed * g_player.turn_direct));
	if (!theres_wall(next.x, g_player.pos.y))
		g_player.pos.x = next.x;
	if (!theres_wall(g_player.pos.x, next.y))
		g_player.pos.y = next.y;
}

static	int    charactere(int y, int x)
{
	if (g_cube.map[y][x] == 'N')
		g_player.rot_ang = radian(270);
	else if (g_cube.map[y][x] == 'W')
		g_player.rot_ang = radian(180);
	else if (g_cube.map[y][x] == 'S')
		g_player.rot_ang = radian(90);
	else if (g_cube.map[y][x] == 'E')
		g_player.rot_ang = radian(0);
	else
		return (0);
	g_player.pos.x = (x * TILE_SIZE + (TILE_SIZE / 2));
	g_player.pos.y = (y * TILE_SIZE + (TILE_SIZE / 2));
	return (1);
}

int    find_p()
{
	int	p;
	int x;
	int	y;

	p = 0;
	y = 0;
	while (g_cube.map[y])
	{
		x = 0;
		while (g_cube.map[y][x])
		{
			if (charactere(y, x))
				p++;
			x++;
		}
		y++;
    }
	if (p == 0)
		return (out("Error\nNo player found!\n"));
	return (p == 1 ? 1 : out("Error\ntoo many players!\n"));
}
