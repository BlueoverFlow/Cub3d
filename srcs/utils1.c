/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:33:01 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/03/01 23:19:19 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"


unsigned int    get_color(int r, int g, int b)
{
    return ((r * 256 * 256) + (g * 256) + b);
}

float           radian(float angle)
{
    return ((float) (angle * M_PI / 180));
}

float      norm_angle(float angle)
{
    while (angle <= 0.0F)
        angle += (2 * M_PI);
    while (angle >= (2 * M_PI))
        angle -= (2 * M_PI);
    return angle;
}

int     out(char *error_msg)
{
    write(2, error_msg, ft_strlen(error_msg));
	exit (0);
    return (-1);
}

float       distanceAB(float Ax, float Ay)
{
    return (sqrt(powf(Ax - g_player.pos.x, 2) + powf(Ay - g_player.pos.y, 2)));
}

int     theres_wall(float x, float y)
{
    float     grid_x;
    float     grid_y;

    if (!(x <= g_cube.map_size.w &&
        x >= 0 && y <= g_cube.map_size.h && y >= 0))
        return (1);
    grid_x = floor(x / (float)TILE_SIZE);
    grid_y = floor(y / (float)TILE_SIZE);
    return (g_cube.map[(int)grid_y][(int)grid_x] == '1' ? 1 : 0);
}