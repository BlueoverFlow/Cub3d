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

void    cast_walls()
{
    int     i;
    int     j;
    t_wall  wall;

    wall.distance = ((float)data.mapd_w / 2.0F) / tanf(radian((FOV / 2)));
    i = 0;
    while (i < data.mapd_w)
    {
        j = 0;
        wall.corr_len = g_rays[i].length * cosf(g_rays[i].ang - player.ang);
        wall.height = (float)data.tile_size / wall.corr_len * (float)wall.distance;
        wall.top = ((float)data.mapd_h / 2.0F) - (wall.height / 2.0F);
        wall.top = wall.top < 0 ? 0 : wall.top;
        wall.bottom = ((float)data.mapd_h / 2.0F) + (wall.height / 2.0F);
        wall.bottom = wall.bottom > data.mapd_h ? data.mapd_h : wall.bottom;
        while (j < wall.top)
                g_main_addr[(j++ * data.mapd_w) + i] = get_color(255, 255, 255);
        j = wall.bottom;
        while (j < data.mapd_h)
                g_main_addr[(j++ * data.mapd_w) + i] = get_color(0, 255, 255);
        ft_wall(wall.top, wall.bottom, wall.height, i);
        ++i;
    }
}

void    ft_wall(int w_top, int w_bottom, int w_height, int index)
{
        int     j;
        int     offset_x;
        int     offset_y;
        int     color;

        if (g_rays[index].hit_ver)
                offset_x = (int)g_rays[index].w_hit.y % data.tile_size;
        else
                offset_x = (int)g_rays[index].w_hit.x % data.tile_size;
        j = w_top;
        offset_y = (j + ((w_height / 2) - (data.mapd_h / 2))) *
                ((float)g_dimd[0].h / (float)w_height);
        
    while (j < w_bottom)
    {
            offset_y = (j + ((w_height / 2) - (data.mapd_h / 2))) *
                    ((float)g_dimd[0].h / (float)w_height);
            if (g_rays[index].hit_hor && g_rays[index].f_up)
                    color = g_north[(offset_y * g_dimd[0].h) + offset_x];
            else if (g_rays[index].hit_hor && g_rays[index].f_down)
                    color = g_south[(offset_y * g_dimd[0].h) + offset_x];
            else if (g_rays[index].hit_ver && g_rays[index].f_left)
                    color = g_west[(offset_y * g_dimd[0].h) + offset_x];
            else if (g_rays[index].hit_ver && g_rays[index].f_right)
                    color = g_east[(offset_y * g_dimd[0].h) + offset_x];
            g_main_addr[(j * data.mapd_w) + index] = color;
            ++j;
    }
}