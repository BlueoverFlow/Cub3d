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

void	get_mapsize()
{
	int w[g_cube.map_size.y];
	int len;
	int j;
	int k;

	k = g_cube.map_size.y + 1;
	j = 0;
	len = (int )ft_strlen(g_cube.world[j]);
	while (--k)
	{
		w[j] = (int )ft_strlen(g_cube.world[j]);
		if (len <= w[j])
			len = w[j];
		j++;
	}
	g_cube.map_size.x = len;
}

void	get_world()
{
	int j;
	int k;

	k = g_cube.map_size.y;
	g_cube.map = malloc(sizeof(char *) * g_cube.map_size.y + 1);
	g_cube.map[g_cube.map_size.y] = NULL;
	while(k--)
	{
		j = -1;
		g_cube.map[k] = ft_calloc(g_cube.map_size.x + 1, sizeof(char));
		while (g_cube.world[k][++j])
			g_cube.map[k][j] = g_cube.world[k][j] == ' ' ? '0' : g_cube.world[k][j];
		while (j < g_cube.map_size.x)
		{
			g_cube.map[k][j] = '0';
			j++;
		}
	}
}
