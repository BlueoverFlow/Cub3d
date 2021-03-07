/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:12:25 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/22 18:05:14 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int				ft_key_pressed(int key)
{
	if (key == 126 || key == 13)
		g_player.move_direction = 1;
	if (key == 125 || key == 1)
		g_player.move_direction = -1;
	if (key == 124)
		g_player.turn_direct = 1;
	if (key == 123)
		g_player.turn_direct = -1;
	if (key == 0)
	{
		g_player.move_direction = 1;
		g_player.side_ang = radian(-90);
	}
	if (key == 2)
	{
		g_player.move_direction = 1;
		g_player.side_ang = radian(90);
	}
	if (key == 46 && !g_player.is_pressed)
		g_player.is_pressed = 1;
	return (0);
}

int				ft_key_released(int key)
{
	if (key == 126 || key == 13)
		g_player.move_direction = 0;
	if (key == 125 || key == 1)
		g_player.move_direction = 0;
	if (key == 124)
		g_player.turn_direct = 0;
	if (key == 123)
		g_player.turn_direct = 0;
	if (key == 0)
	{
		g_player.move_direction = 0;
		g_player.side_ang = radian(0);
	}
	if (key == 2)
	{
		g_player.move_direction = 0;
		g_player.side_ang = radian(0);
	}
	if (key == 46)
		g_player.is_pressed = 0;
	return (0);
}

int		render(void)
{
	t_dim	next;

	next.x = g_player.pos.x + g_player.move_speed * g_player.move_direction * cosf(g_player.rot_ang + g_player.side_ang);
	next.y = g_player.pos.y + g_player.move_speed * g_player.move_direction * sinf(g_player.rot_ang + g_player.side_ang);
	g_player.rot_ang = norm_angle((g_player.rot_ang + g_player.rot_speed * g_player.turn_direct));
	if (!is_wall(next.x, g_player.pos.y))
		g_player.pos.x = next.x;
	if (!is_wall(g_player.pos.x, next.y))
		g_player.pos.y = next.y;
	if (g_player.move_direction || g_player.turn_direct || g_player.is_pressed)
	{
		cast_rays(g_player.pos.x, g_player.pos.y, g_player.rot_ang);
		cast_walls();
	}
	return (0);
}
