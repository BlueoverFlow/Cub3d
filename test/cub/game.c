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

#include "../include/cub_header.h"

int				ft_key_pressed(int key)
{
	if (key == 126 || key == 13)
		g_p.move_direct = 1;
	if (key == 125 || key == 1)
		g_p.move_direct = -1;
	if (key == 124)
		g_p.turn_direct = 1;
	if (key == 123)
		g_p.turn_direct = -1;
	if (key == 0)
	{
		g_p.move_direct = 1;
		g_p.side_ang = ft_radian(-90);
	}
	if (key == 2)
	{
		g_p.move_direct = 1;
		g_p.side_ang = ft_radian(90);
	}
	if (key == 46 && !g_is_pressed)
		g_is_pressed = 1;
	return (0);
}

int				ft_key_released(int key)
{
	if (key == 126 || key == 13)
		g_p.move_direct = 0;
	if (key == 125 || key == 1)
		g_p.move_direct = 0;
	if (key == 124)
		g_p.turn_direct = 0;
	if (key == 123)
		g_p.turn_direct = 0;
	if (key == 0)
	{
		g_p.move_direct = 0;
		g_p.side_ang = ft_radian(0);
	}
	if (key == 2)
	{
		g_p.move_direct = 0;
		g_p.side_ang = ft_radian(0);
	}
	if (key == 46)
		g_is_pressed = 0;
	return (0);
}

int				ft_update(void)
{
	ft_update_all();
	return (0);
}
