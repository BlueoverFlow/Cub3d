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

#include "../include/cub_header.h"

float			ft_radian(float angle)
{
	return ((float)(angle * M_PI / 180));
}

float			ft_distance(float x, float y)
{
	return (sqrt(powf(x - g_p.axis.x, 2) + powf(y - g_p.axis.y, 2)));
}

float			ft_norm_angle(float angle)
{
	if (angle >= ft_radian(360.0F))
		angle -= ft_radian(360.0F);
	else if (angle <= ft_radian(0.0F))
		angle += ft_radian(360.0F);
	return (angle);
}

unsigned int	ft_color_s(t_color color)
{
	return ((color.r * 256 * 256) + (color.g * 256) + color.b);
}
