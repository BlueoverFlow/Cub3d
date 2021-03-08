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

void	get_world()
{
	int j;
	int k;

	k = g_cube.rows;
	g_cube.map = malloc(sizeof(char *) * g_cube.rows + 1);
	g_cube.map[g_cube.rows] = NULL;
	while(k--)
	{
		j = -1;
		g_cube.map[k] = ft_calloc(g_cube.cols + 1, sizeof(char));
		while (g_cube.world[k][++j])
			g_cube.map[k][j] = g_cube.world[k][j] == ' ' ? '0' : g_cube.world[k][j];
		while (j < g_cube.cols)
		{
			g_cube.map[k][j] = '0';
			j++;
		}
	}
}

void	read_map()
{
	char    *line;
	int     fd;
	int     j;

	j = 0;
	if (g_cube.rows > 0)
	{
		g_cube.world = malloc((sizeof(char *) * g_cube.rows) + 1);
		g_cube.world[g_cube.rows] = NULL;
	}
	fd = open(file.file, O_RDONLY);
	while (--file.map_pos)
	{
		get_next_line(fd, &line);
		free(line);
	}
	while (get_next_line(fd, &line) > 0)
	{
		g_cube.world[j] = ft_strdup(line);
		free(line);
		j++;
	}
	g_cube.world[j] = ft_strdup(line);
	free(line);
	close (fd);
}
