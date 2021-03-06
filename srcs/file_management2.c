/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 06:34:54 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 03:22:41 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	get_mapwidth()
{
	int w[data.map_height];
	int len;
	int j;
	int k;

	k = data.map_height + 1;
	j = 0;
	len = (int )ft_strlen(data.map[j]);
	while (--k)
	{
		w[j] = (int )ft_strlen(data.map[j]);
		if (len <= w[j])
			len = w[j];
		j++;
	}
	data.map_width = len;
}

void	get_world()
{
	int j;
	int k;

	k = data.map_height;
	data.world = malloc(sizeof(char *) * data.map_height + 1);
	data.world[data.map_height] = NULL;
	while(k--)
	{
		j = -1;
		data.world[k] = ft_calloc(data.map_width + 1, sizeof(char));
		while (data.map[k][++j])
			data.world[k][j] = data.map[k][j] == ' ' ? '0' : data.map[k][j];
		while (j < data.map_width)
		{
			data.world[k][j] = '0';
			j++;
		}
	}
	data.mapd_w = TILE_SIZE * data.map_width;
	data.mapd_h = TILE_SIZE * data.map_height;
}
