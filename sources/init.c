/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:52:17 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/09 10:36:11 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
void	set_window(t_meta *data)
{
	mlx_get_screen_size(data->mlx, &data->win_width, &data->win_height);
	printf("%d x %d\n", data->win_width, data->win_height);
	if (WIDTH < data->win_width)
		data->win_width = WIDTH;
	if (HEIGHT < data->win_height)
		data->win_height = HEIGHT;
}

int	map_definition(int fd, t_meta *data)
{
	int		i;
	int		error_token;
	char	*line;

	error_token = 0;
	line = get_next_line(fd);
	if (!line)
		return (free(line), 1);
	data->map.width = (ft_countword(line, " \n"));
	i = 0;
	while (line)
	{
		if ((int)(ft_countword(line, " \n")) != data->map.width)
			error_token = 1;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->map.height = i;
	return (error_token);
}

void	view_definition(t_meta *data)
{
	data->map.altitude = 0.1;
	data->map.angle = 30;
	data->map.mov_x = data->win_width / 2;
	data->map.mov_y = 50;
	data->map.zoom = 30;
}

void	set_extremum(t_point **tab, t_map *map)
{
	int	i;
	int	j;

	map->min = 0;
	map->max = 0;
	j = (-1);
	while (++j < map->height)
	{
		i = (-1);
		while (++i < map->width)
		{
			if (map->min > tab[j][i].z)
				map->min = tab[j][i].z;
			if (map->max < tab[j][i].z)
				map->max = tab[j][i].z;
		}
	}
}

t_point	**map_malloc(t_meta *data)
{
	int		j;
	t_point	**tab;

	tab = (t_point **)malloc(sizeof(t_point *) * data->map.height);
	if (!tab)
		return (NULL);
	j = 0;
	while (j < data->map.height)
	{
		tab[j] = (t_point *)malloc(sizeof(t_point) \
			* (data->map.width));
		if (!(tab[j]))
		{
			while (--j >= 0)
				free(tab[j]);
			free(tab);
			return (NULL);
		}
		j++;
	}
	return (tab);
}
