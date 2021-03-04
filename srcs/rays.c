/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:33:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/02/25 17:04:13 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static  void    rays_init(t_ray *rays)
{
    if (rays != NULL)
    {
        rays->length = 0;
        rays->w_hit.x = 0.0F;
        rays->w_hit.y = 0.0F;
        rays->hit_hor = 0.0F;
        rays->hit_ver = 0.0F;
        rays->f_down = (rays->ang > 0 && rays->ang < M_PI);
        rays->f_up = !rays->f_down;
        rays->f_right = ((rays->ang < 0.5 * M_PI) || (rays->ang > 1.5 * M_PI));
        rays->f_left = !rays->f_right;
    }
}


static t_grides     hor_intercept(t_ray *rays)
{
    t_grides hor;   

    hor.len = 1000000000;
    hor.intercept.y = floorf(player->y / (float)data->tile_size) * (float)data->tile_size;
    hor.intercept.y += (rays->f_down ? (float)data->tile_size : 0.0F);
    hor.intercept.x = player->x + (hor.intercept.y - player->y) / tanf(rays->ang);
    hor.step.y = (float)data->tile_size;
    hor.step.y *= (rays->f_up ? -1.0F : 1.0F);
    hor.step.x = (float)data->tile_size / tanf(rays->ang);
    hor.step.x *= (rays->f_left && hor.step.x > 0.0F) ? -1.0F : 1.0F;
    hor.step.x *= (rays->f_right && hor.step.x < 0.0F) ? -1.0F : 1.0F;
    hor.hit.x = hor.intercept.x;
    hor.hit.y = hor.intercept.y;
    while (hor.hit.y >= 0.0F && hor.hit.y < (float)data->mapd_h
            && hor.hit.x >= 0.0F && hor.hit.x < (float)data->mapd_w)
    {
        if (theres_wall(hor.hit.x, rays->f_up ? hor.hit.y - 1 : hor.hit.y))
        {
            hor.len = distanceAB(hor.hit.x, hor.hit.y);
            break;
        }
        hor.hit.x += hor.step.x;
        hor.hit.y += hor.step.y;
    }
    return (hor);
}

static t_grides     ver_intercept(t_ray *rays)
{
    t_grides ver;

    ver.len = 1000000000;
    ver.intercept.x = floorf(player->x / (float)data->tile_size) * (float)data->tile_size;
    ver.intercept.x += (rays->f_right ? (float)data->tile_size : 0.0F);
    ver.intercept.y = player->y + (ver.intercept.x - player->x) * tanf(rays->ang);
    ver.step.x = (float)data->tile_size;
    ver.step.x *= (rays->f_left ? -1.0F : 1.0F);
    ver.step.y = (float)data->tile_size * tanf(rays->ang);
    ver.step.y *= (rays->f_up && ver.step.y > 0.0F) ? -1.0F : 1.0F;
    ver.step.y *= (rays->f_down && ver.step.y < 0.0F) ? -1.0F : 1.0F;
    ver.hit.x = ver.intercept.x;
    ver.hit.y = ver.intercept.y;
    while (ver.hit.y >= 0.0F && ver.hit.y < (float)data->mapd_h
            && ver.hit.x >= 0.0F && ver.hit.x < (float)data->mapd_w)
    {
        if (theres_wall(rays->f_left ? ver.hit.x - 1 : ver.hit.x, ver.hit.y))
        {
            ver.len = distanceAB(ver.hit.x, ver.hit.y);
            break;
        }
        ver.hit.x += ver.step.x;
        ver.hit.y += ver.step.y;
    }
    return (ver);
}

static void         longer_len(t_ray *rays)
{
    t_grides hor;
    t_grides ver;

    rays_init(rays);
    hor = hor_intercept(rays);
    ver = ver_intercept(rays);
    if (ver.len > hor.len)
    {
        rays->length = hor.len;
        rays->hit_hor = 1;
        rays->hit_ver = 0;
        rays->w_hit.x = hor.hit.x;
        rays->w_hit.y = hor.hit.y;
    }
    else
    {
        rays->length = ver.len;
        rays->hit_ver = 1;
        rays->hit_hor = 0;
        rays->w_hit.x = ver.hit.x;
        rays->w_hit.y = ver.hit.y;
    }
}

void cast_rays()
{
    int     i;
    float   angle;

    i = -1;
    angle = player->ang - radian(FOV / 2);
    while (++i < data->window_width)
    {
        g_rays[i].ang = norm_angle(angle);
        longer_len(&g_rays[i]);
        draw_line(g_rays[i].length, player->x, player->y, g_rays[i].ang, get_color(255, 255, 0));
        angle += radian(FOV) / data->window_width;
    }
}

// void                    cast_walls(void)
// {
// 	int	i;
// 	int	j;
// 	t_wall     wall;

// 	wall.pp_dist = ((float)data->window_width / 2.0F) / tanf(radian((FOV / 2)));
// 	i = -1;
// 	while (++i < data->window_width)
// 	{
// 		wall.corr_len = g_rays[i].length * cosf(g_rays[i].ang - player->ang);
// 		wall.hieght = (float)TILE_SIZE / wall.corr_len * (float)wall.pp_dist;
// 		wall.top = ((float)data->window_height / 2.0F) - (wall.hieght / 2.0F);
// 		wall.top = wall.top < 0 ? 0 : wall.top;
// 		wall.bottom = ((float)data->window_height/ 2.0F) + (wall.hieght / 2.0F);
// 		wall.bottom = wall.bottom > data->window_height ? data->window_height : wall.bottom;
// 		j = 0;
// 		while (j < wall.top)
// 				g_data_3d[(j++ * data->window_width) + i] = get_color(255, 0, 0);
// 		j = wall.bottom;
// 		while (j < data->window_height)
// 				g_data_3d[(j++ * data->window_width) + i] = get_color(0, 255, 0);
// 		ft_wall(wall.top, wall.bottom, wall.hieght, i);
// 	}
// }

// void                    ft_wall(int w_top, int w_bottom, int w_height, int index)
// {
// 	int j;
// 	int offset_x;
// 	int offset_y;
// 	int color;

// 	if (g_rays[index].hit_ver)
// 			offset_x = (int)g_rays[index].w_hit.y % TILE_SIZE;
// 	else
// 			offset_x = (int)g_rays[index].w_hit.x % TILE_SIZE;
// 	j = w_top;
// 	while (j < w_bottom)
// 	{
// 		offset_y = (j + ((w_height / 2) - (data->window_height / 2))) *
// 				((float)g_dimd[0].h / (float)w_height);
// 		if (g_rays[index].hit_hor && g_rays[index].f_up)
// 				color = g_data_n[(offset_y * g_dimd[0].h) + offset_x];
// 		else if (g_rays[index].hit_hor && g_rays[index].f_down)
// 				color = g_data_s[(offset_y * g_dimd[0].h) + offset_x];
// 		else if (g_rays[index].hit_ver && g_rays[index].f_left)
// 				color = g_data_w[(offset_y * g_dimd[0].h) + offset_x];
// 		else if (g_rays[index].hit_ver && g_rays[index].f_right)
// 				color = g_data_e[(offset_y * g_dimd[0].h) + offset_x];
// 		g_data_3d[(j * data->window_width) + index] = color;
// 		++j;
// 	}
// }