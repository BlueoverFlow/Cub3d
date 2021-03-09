/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_handling2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:33:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/02/25 17:30:00 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static int		map_parsing(int k, int j)
{
	int x;
	int y;

	y = -2;
	x = -2;
	while (++y < 2)
	{
		if (k + y >= g_cube.cols || k <= 0)
			return (0);
		if (g_cube.world[k + y][j] == ' ' || g_cube.world[k + y][j] == '\0')
			return (0);
	}
	while (++x < 2)
	{
		if ((j + x + 1 > ft_strlen(g_cube.world[k]) || j <= 0))
			return (0);
		if (g_cube.world[k][j + x] == ' ')
			return (0);
	}
	return (1);
}

int		handle_map()
{
	int	k;
	int j;

	if (g_cube.rows < 3 || g_cube.cols < 3)
		return (out("unvalid map/map unfound!\n"));
	k = g_cube.rows;
	while (k--)
	{
		j = -1;
		while (g_cube.world[k][++j])
		{
			if (!(ft_strnchar("NEWS120 ", g_cube.world[k][j])))
				return (out("Fobidden character exist in map!\n"));
			else if ((ft_strnchar("NEWS20", g_cube.world[k][j])) && !(map_parsing(k, j)))
				return (out("Map is not properly closed!\n"));
		}
	}
	return (1);
}

int		handle_F_C()
{
	char 	**id[4];
	int		i;

	id[0] = find_id("F");
	id[1] = find_id("C");
	if (ft_strlen_2d(id[0]) != 2)
		return (out("Can't find Floor data/invalid data format!"));
	if (ft_strlen_2d(id[1]) != 2)
		return (out("Can't find Ceilling data/invalid data format!"));
	if (!(id[2] = ft_split(id[0][1], ',')) || !(id[3] = ft_split(id[1][1], ',')))
		return(out("invalid RGB color!"));
	i = 0;
	while (id[2][i] && id[3][i])
	{
		g_cube.floor[i] = ft_atoi(id[2][i]);
		g_cube.ceilling[i] = ft_atoi(id[3][i]);
		if (!(g_cube.floor[i] >= 0 && g_cube.floor[i] <= 255) || !(g_cube.ceilling[i] >= 0 && g_cube.ceilling[i] <= 255))
			return(out("invalid RGB color!"));
		i++;
	}
	if (i != 3)
		return(out("invalid RGB color!"));
	i = -1;
	while (id[i++])
		free(id[i]);
	return (1);
}