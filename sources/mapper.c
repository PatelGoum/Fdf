/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:00 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/06 10:50:49 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_reader(int fd, t_point **tab)
{
	int		i;
	int		j;
	char	*temp;
	char	**temp_z;

	j = 0;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		i = (-1);
		temp_z = ft_split(temp, " \n");
		while (temp_z[++i])
		{
			tab[j][i].x = i;
			tab[j][i].y = j;
			i += color_handler(temp_z[i], &tab[j][i]);
			if (temp_z[i])
				free(temp_z[i]);
		}
		free(temp_z);
		free(temp);
		temp = get_next_line(fd);
		j++;
	}
	free(temp);
}

int	color_handler(const char *temp_z, t_point *cell)
{
	char	**fcolor;

	if (ft_strchr(temp_z, ','))
	{
		fcolor = ft_split(temp_z, ",");
		if (!(fcolor))
			return (-1);
		cell->z = ft_atoi(fcolor[0]);
		cell->color = ft_atoi_base16(fcolor[1]);
		free(fcolor[0]);
		free(fcolor[1]);
		free(fcolor);
	}
	else
	{
		cell->z = ft_atoi(temp_z);
		cell->color = 0;
	}
	return (0);
}

int	map_converter(t_meta *data)
{
	int		i;
	int		j;
	float	rad;

	rad = data->map.angle * 3.141593 / 180;
	j = (-1);
	while (++j < data->map.height)
	{
		i = (-1);
		while (++i < data->map.width)
		{
			data->points2d[j][i].x = data->map.mov_x + data->map.zoom \
				* (data->points3d[j][i].x * cosf(rad) + data->points3d[j][i].y \
				* cosf(rad + 2) + data->points3d[j][i].z * cosf(rad - 2) \
				* data->map.altitude);
			data->points2d[j][i].y = data->map.mov_y + data->map.zoom \
				* (data->points3d[j][i].x * sinf(rad) + data->points3d[j][i].y \
				* sinf(rad + 2) + data->points3d[j][i].z * sinf(rad - 2) \
				* data->map.altitude);
			data->points2d[j][i].z = data->points3d[j][i].z;
			data->points2d[j][i].color = color_set(data->points3d[j][i], data);
		}
	}
	return (0);
}

int	draw_map(t_meta *data)
{
	int	i;
	int	j;

	j = (-1);
	while (++j < (data->map.height - 1))
	{
		i = (-1);
		while (++i < (data->map.width - 1))
		{
			draw_line(data->points2d[j][i], data->points2d[j][i + 1], data);
			draw_line(data->points2d[j][i], data->points2d[j + 1][i], data);
		}
		draw_line(data->points2d[j][i], data->points2d[j + 1][i], data);
	}
	i = (-1);
	while (++i < (data->map.width - 1))
		draw_line(data->points2d[j][i], data->points2d[j][i + 1], data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.address, 0, 0);
	return (0);
}
