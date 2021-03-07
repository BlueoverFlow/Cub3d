/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap.cub                                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:46:40 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 03:20:32 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	read_file()
{
	read_elements();
	read_map();
	get_mapsize();
}

void	read_elements()
{
	char    *line;
	int     fd;
	int     i;

	i = 0;
	fd = open(file.file, O_RDONLY);
	while (i < 8)
	{
		if (get_next_line(fd, &line) > 0)
		{ 
			if ((ft_split(line, ' ')) && *line != '\0' && *line != '\n')
			{
				file.elem[i] = ft_strdup(line);
				i++;
			}
			file.map_pos++;
			free(line);
		}
		else
			break;
	}
	the9th_elem(line, fd);
}

void	the9th_elem(char *line, int fd)
{
	char    **check;
	char	**tmp;
	int     *i;
	int     r;

	while (get_next_line(fd, &line) > 0)
	{
		check = ft_split(line, ' ');
		if (*check)
		{
			if (**check == '1' || **check == '0' || ** check == '2')
			{
				g_cube.map_size.y++;
				while (get_next_line(fd, &line) > 0)
				{
					g_cube.map_size.y++;
					free(line);
				}
				break;
			}
		}
		file.map_pos++;
		free(line);
	}
	close (fd);
}

void	read_map()
{
	char    *line;
	int     fd;
	int     j;

	j = 0;
	if (g_cube.map_size.y > 0)
	{
		g_cube.world = malloc((sizeof(char *) * g_cube.map_size.y) + 1);
		g_cube.world[g_cube.map_size.y] = NULL;
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