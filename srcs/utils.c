/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:48 by ael-mezz          #+#    #+#             */
/*   Updated: 2020/03/06 22:19:14 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void            colored_square(int scale, int x, int y, int color)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	while (x1 < (x + scale))
	{
		while(y1 < (y + scale))
		{
			my_mlx_pixel_put(draw, x1, y1, color);
			y1++;
		}
		y1 = y;
		x1++;
	}
}

unsigned int    get_color(int r, int g, int b)
{
    return ((r * 256 * 256) + (g * 256) + b);
}

void            print_circle(int x, int y, int r, int color)
{
    int ang_save;
    int ang;

    ang = 0;
    ang_save = ang;
    while (r >= 0)
    {
        while (ang < 360)
        {
            my_mlx_pixel_put(draw, (r * cosf(ang * M_PI / 180) + x), (r * sinf(ang * M_PI / 180)+ y), color);
            ang++;
        }
        ang = ang_save;
        r -= 1;
    }
}

void            draw_line(int l, int x, int y, float ang, int color)
{
    int l0;

    l0 = -1;
    while (--l >= 0)
            my_mlx_pixel_put(draw, (l * cosf(ang)) + x, (l * sinf(ang)) + y, color);
}

float           radian(float angle)
{
    return ((float) (angle * M_PI / 180));
}

void    my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char    *dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
 	*(unsigned int*)dst = color;
}

float      norm_angle(float angle)
{
    while (angle <= -(2 * M_PI))
        angle += (2 * M_PI);
    while (angle >= (2 * M_PI))
        angle -= (2 * M_PI);
    return angle;
}

float       distanceAB(float Ax, float Ay)
{
    return (sqrt(powf(Ax - player->x, 2) + powf(Ay - player->y, 2)));
}

int     theres_wall(float x, float y)
{
    float     grid_x;
    float     grid_y;

    if (!(x <= data->window_width &&
        x >= 0 && y <= data->window_height && y >= 0))
        return (1);
    grid_x = floor(x / data->tile_size);
    grid_y = floor(y / data->tile_size);
    return (data->world[(int)grid_y][(int)grid_x] == '1' ? 1 : 0);
}

int     out(char *error_msg)
{
    write(2, error_msg, ft_strlen(error_msg));
	exit (0);
    return (-1);
}

// for (int i = 0; data->world[i]; i++)
// {
//     for (int j = 0; data->world[i][j]; j++)
//         printf("%c", data->world[i][j]);
//     printf("\n");
// }

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1))
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	else
		return (0);
}

int		ft_strlen_2d(char **str)
{
        int     i;

        i = 0;
        while (str && str[i] != NULL)
                i++;
        return (i);
}

int		free_2d(char **str)
{
        int             i;

        i = 0;
        while (str[i] != NULL)
                free(str[i++]);
        free(str);
        return (0);
}


int		ft_strnchar(const char *str, char c)
{
	int i;
	
	i = -1;
	while (str[++i])
		if (str[i] == c)
				return (1);
	return (0);
}
