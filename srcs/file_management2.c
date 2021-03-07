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
	int w[g_data.rows];
	int len;
	int j;
	int k;

	k = g_data.rows + 1;
	j = 0;
	len = (int )ft_strlen(g_data.world[j]);
	while (--k)
	{
		w[j] = (int )ft_strlen(g_data.world[j]);
		if (len <= w[j])
			len = w[j];
		j++;
	}
	g_data.cols = len;
}

void	get_world()
{
	int j;
	int k;

	k = g_data.rows;
	g_data.map = malloc(sizeof(char *) * g_data.rows + 1);
	g_data.map[g_data.rows] = NULL;
	while(k--)
	{
		j = -1;
		g_data.map[k] = ft_calloc(g_data.cols + 1, sizeof(char));
		while (g_data.world[k][++j])
			g_data.map[k][j] = g_data.world[k][j] == ' ' ? '0' : g_data.world[k][j];
		while (j < g_data.cols)
		{
			g_data.map[k][j] = '0';
			j++;
		}
	}
}
