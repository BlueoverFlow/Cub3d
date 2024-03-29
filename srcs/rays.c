/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:12:25 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/22 17:25:04 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void			ray_init(t_ray *ray)
{
	if (ray != NULL)
	{
		ray->length = 0;
		ray->w_hit.x = 0;
		ray->w_hit.y = 0;
		ray->hit_hor = 0;
		ray->hit_ver = 0;
		ray->r_down = (ray->angle > 0 && ray->angle < M_PI);
		ray->r_up = !ray->r_down;
		ray->r_right = ((ray->angle < 0.5 * M_PI) || (ray->angle > 1.5 * M_PI));
		ray->r_left = !ray->r_right;
	}
}

static t_grides	ft_horizontal(t_ray *ray)
{
	t_grides	hor;

	hor.len = 1000000000;
	hor.inter.y = floorf(g_player.pos.y / (float)TILE_SIZE) * (float)TILE_SIZE;
	hor.inter.y += (ray->r_down ? (float)TILE_SIZE : 0.0F);
	hor.inter.x = g_player.pos.x + (hor.inter.y - g_player.pos.y) / tanf(ray->angle);
	hor.step.y = (float)TILE_SIZE;
	hor.step.y *= (ray->r_up ? -1.0F : 1.0F);
	hor.step.x = (float)TILE_SIZE / tanf(ray->angle);
	hor.step.x *= (ray->r_left && hor.step.x > 0.0F) ? -1.0F : 1.0F;
	hor.step.x *= (ray->r_right && hor.step.x < 0.0F) ? -1.0F : 1.0F;
	hor.hit.x = hor.inter.x;
	hor.hit.y = hor.inter.y;
	while (hor.hit.y >= 0.0F && hor.hit.y < (float)g_cube.map_size.h
		&& hor.hit.x >= 0.0F && hor.hit.x < (float)g_cube.map_size.w)
	{
		if (theres_wall(hor.hit.x, ray->r_up ? hor.hit.y - 1 : hor.hit.y))
		{
			hor.len = distanceAB(hor.hit.x, hor.hit.y);
			break ;
		}
		hor.hit.x += hor.step.x;
		hor.hit.y += hor.step.y;
	}
	return (hor);
}

static t_grides	ft_vertical(t_ray *ray)
{
	t_grides	ver;

	ver.len = 1000000000;
	ver.inter.x = floorf(g_player.pos.x / (float)TILE_SIZE) * (float)TILE_SIZE;
	ver.inter.x += (ray->r_right ? (float)TILE_SIZE : 0.0F);
	ver.inter.y = g_player.pos.y + (ver.inter.x - g_player.pos.x) * tanf(ray->angle);
	ver.step.x = (float)TILE_SIZE;
	ver.step.x *= (ray->r_left ? -1.0F : 1.0F);
	ver.step.y = (float)TILE_SIZE * tanf(ray->angle);
	ver.step.y *= (ray->r_up && ver.step.y > 0.0F) ? -1.0F : 1.0F;
	ver.step.y *= (ray->r_down && ver.step.y < 0.0F) ? -1.0F : 1.0F;
	ver.hit.x = ver.inter.x;
	ver.hit.y = ver.inter.y;
	while (ver.hit.y >= 0.0F && ver.hit.y < (float)g_cube.map_size.h
		&& ver.hit.x >= 0.0F && ver.hit.x < (float)g_cube.map_size.w)
	{
		if (theres_wall(ray->r_left ? ver.hit.x - 1 : ver.hit.x, ver.hit.y))
		{
			ver.len = distanceAB(ver.hit.x, ver.hit.y);
			break ;
		}
		ver.hit.x += ver.step.x;
		ver.hit.y += ver.step.y;
	}
	return (ver);
}

static void		longer_ray(t_ray *ray)
{
	t_grides	hor;
	t_grides	ver;

	ray_init(ray);
	hor = ft_horizontal(ray);
	ver = ft_vertical(ray);
	if (ver.len > hor.len)
	{
		ray->length = hor.len;
		ray->hit_hor = 1;
		ray->hit_ver = 0;
		ray->w_hit.x = hor.hit.x;
		ray->w_hit.y = hor.hit.y;
	}
	else
	{
		ray->length = ver.len;
		ray->hit_ver = 1;
		ray->hit_hor = 0;
		ray->w_hit.x = ver.hit.x;
		ray->w_hit.y = ver.hit.y;
	}
}

void				cast_rays()
{
	int		i;
	float	ang;

	i = 0;
	ang = g_player.rot_ang - radian((float)(FOV / 2));
	while (i < g_cube.dimens.w)
	{
		g_rays[i].angle = norm_angle(ang);
		longer_ray(&g_rays[i]);
		ang += radian(g_cube.ratio);
		++i;
	}
}