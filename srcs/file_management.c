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

static	void	the9th_elem(char *line, int fd)
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
				g_cube.rows++;
				while (get_next_line(fd, &line) > 0)
				{
					g_cube.rows++;
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

static void	read_elements()
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

static	void	get_mapwidth()
{
	int w[g_cube.rows];
	int len;
	int j;
	int k;

	k = g_cube.rows + 1;
	j = 0;
	len = (int )ft_strlen(g_cube.world[j]);
	while (--k)
	{
		w[j] = (int )ft_strlen(g_cube.world[j]);
		if (len <= w[j])
			len = w[j];
		j++;
	}
	g_cube.cols = len;
}

void	read_file()
{
	read_elements();
	read_map();
	get_mapwidth();
}
