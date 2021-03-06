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
	hor.intercept.y = floorf(player.y / (float)TILE_SIZE) * (float)TILE_SIZE;
	hor.intercept.y += (rays->f_down ? (float)TILE_SIZE : 0.0F);
	hor.intercept.x = player.x + (hor.intercept.y - player.y) / tanf(rays->ang);
	hor.step.y = (float)TILE_SIZE;
	hor.step.y *= (rays->f_up ? -1.0F : 1.0F);
	hor.step.x = (float)TILE_SIZE / tanf(rays->ang);
	hor.step.x *= (rays->f_left && hor.step.x > 0.0F) ? -1.0F : 1.0F;
	hor.step.x *= (rays->f_right && hor.step.x < 0.0F) ? -1.0F : 1.0F;
	hor.hit.x = hor.intercept.x;
	hor.hit.y = hor.intercept.y;
	while (hor.hit.y >= 0.0F && hor.hit.y < (float)data.mapd_h
			&& hor.hit.x >= 0.0F && hor.hit.x < (float)data.mapd_w)
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
	ver.intercept.x = floorf(player.x / (float)TILE_SIZE) * (float)TILE_SIZE;
	ver.intercept.x += (rays->f_right ? (float)TILE_SIZE : 0.0F);
	ver.intercept.y = player.y + (ver.intercept.x - player.x) * tanf(rays->ang);
	ver.step.x = (float)TILE_SIZE;
	ver.step.x *= (rays->f_left ? -1.0F : 1.0F);
	ver.step.y = (float)TILE_SIZE * tanf(rays->ang);
	ver.step.y *= (rays->f_up && ver.step.y > 0.0F) ? -1.0F : 1.0F;
	ver.step.y *= (rays->f_down && ver.step.y < 0.0F) ? -1.0F : 1.0F;
	ver.hit.x = ver.intercept.x;
	ver.hit.y = ver.intercept.y;
	while (ver.hit.y >= 0.0F && ver.hit.y < (float)data.mapd_h
			&& ver.hit.x >= 0.0F && ver.hit.x < (float)data.mapd_w)
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
	angle = player.ang - radian(FOV / 2);
	while (++i <= data.window_width)
	{
		g_rays[i].ang = norm_angle(angle);
		longer_len(&g_rays[i]);
		// draw_line(g_rays[i].length, player.x, player.y, g_rays[i].ang, get_color(255, 255, 0));
		angle += radian(FOV) / data.window_width;
	}
}