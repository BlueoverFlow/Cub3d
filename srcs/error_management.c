/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:33:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 22:19:14 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"


static	int     check_g_filename(char *ext)
{
    int     len;

    len = ft_strlen(g_file.file);
	return (ft_strcmp(&(g_file.file[len - 4]), ext) == 0 ? 0 : -1);
}

static	int     check_args()
{
    if (g_file.argc < 2)
        return (out("Error\nAt least 1 argument is required!\n"));
    if (g_file.argc > 3)
        return (out("Error\nneed only 2 argument maximum\n"));
    if (check_g_filename(".cub") == -1)
        return (out("Error\nneed a \".cub\" g_file!\n"));
    if (g_file.argc == 3 && ft_strcmp(g_file.argv[2], "--save") == 0)
        g_file.screenshot = 1;
    else if (g_file.argc == 3)
        return (out("Error\ndo you mean \"--save\"?!\n"));
    return (1);
}

static	int		check_elements()
{
	handle_r();
	texture_data();
	handle_F_C();
	handle_map();
	return (1);
}

int     check_err()
{
    check_args();
    if (open(g_file.file, O_RDONLY) < 0)
        return (out("Error\ncan't find your \".cub\" g_file!\n"));
	read_file();
	check_elements();
    return (1);
}