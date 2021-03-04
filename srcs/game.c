/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:39:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 22:10:14 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	move_player()
{
	float x;
	float y;

	player.ang = norm_angle(player.rot_ang + player.direction);
	norm_angle(player.side_ang);
	x = player.x + player.move_speed * player.move_direction * cosf(player.ang + player.side_ang);
	y = player.y + player.move_speed * player.move_direction * sinf(player.ang + player.side_ang);
	if (!theres_wall(x , player.y))
			player.x = x;
	if (!theres_wall(player.x, y))
			player.y = y;
}

int		key_pressed(int key)
{
	if (key == KEY_W)
			player.move_direction = 1;
	else if (key == KEY_S)
			player.move_direction = -1;
	else if (key == KEY_D)
	{
			player.move_direction = 1;
			player.side_ang = radian(90);
	}
	else if (key == KEY_A)
	{
			player.move_direction = 1;
			player.side_ang = radian(-90);
	} 
	else if (key == KEY_RIGHT)
			player.direction += player.rot_speed;
	else if (key == KEY_LEFT)
			player.direction -= player.rot_speed;
	return (0);
}

int		key_released(int key)
{
	if (key == KEY_UP || key == KEY_W)
			player.move_direction = 0;
	else if (key == KEY_S)
			player.move_direction = 0;
	else if (key == KEY_D)
	{
			player.move_direction = 0;
			player.side_ang = 0;
	}
	else if (key == KEY_A)
	{
			player.move_direction = 0;
			player.side_ang = 0;
	}
	else if (key == KEY_RIGHT)
			player.direction = 0;
	else if (key == KEY_LEFT)
			player.direction = 0;
	return (0);
}

int		update()
{
	make_map2d();
	move_player();
	cast_rays();
	print_circle(player.x, player.y, player.scale, get_color(255, 0, 0));
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, draw.img, 0, 0);
	return (0);
}