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
		g_player.move_direct = 1;
	if (key == 125 || key == 1)
		g_player.move_direct = -1;
	if (key == 124)
		g_player.turn_direct = 1;
	if (key == 123)
		g_player.turn_direct = -1;
	if (key == 0)
	{
		g_player.move_direct = 1;
		g_player.side_ang = radian(-90);
	}
	if (key == 2)
	{
		g_player.move_direct = 1;
		g_player.side_ang = radian(90);
	}
	if (key == 53)
		exit_game();
	return (0);
}

int				ft_key_released(int key)
{
	if (key == 126 || key == 13)
		g_player.move_direct = 0;
	if (key == 125 || key == 1)
		g_player.move_direct = 0;
	if (key == 124)
		g_player.turn_direct = 0;
	if (key == 123)
		g_player.turn_direct = 0;
	if (key == 0)
	{
		g_player.move_direct = 0;
		g_player.side_ang = radian(0);
	}
	if (key == 2)
	{
		g_player.move_direct = 0;
		g_player.side_ang = radian(0);
	}
	return (0);
}

int		render_()
{
	move_player();
	if (g_player.move_direct || g_player.turn_direct)
	{
		cast_rays();
		cast_walls();
		
	}
	return (0);
}