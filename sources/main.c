/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:25 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/09 10:44:14 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_meta	data;
	int		fd;

	if (ac != 2)
		return (1);
	data.map_path = ft_strdup(av[1]);
	if (check_format(data.map_path))
		return (free(data.map_path), 1);
	fd = open(data.map_path, O_RDONLY);
	if (map_definition(fd, &data))
		return (close(fd), free(data.map_path), 1);
	close(fd);
	data.points3d = map_malloc(&data);
	data.points2d = map_malloc(&data);
	if (!data.points2d || !data.points3d)
		return (1);
	fd = open(data.map_path, O_RDONLY);
	map_reader(fd, (data.points3d));
	close(fd);
	set_extremum(data.points3d, &(data.map));
	if (start(&data) == 1)
		return (1);
	return (0);
}

int	start(t_meta *data)
{
	data->mlx = mlx_init();
	if (!data->mlx || !data->map_path)
		return (1);
	set_window(data);
	data->win = mlx_new_window(data->mlx, data->win_width, \
		data->win_height, "My FdF");
	if (!data->win)
		return (close_win(data), 1);
	data->img.address = mlx_new_image(data->mlx, data->win_width, \
		data->win_height);
	if (!data->img.address)
		return (close_win(data), 1);
	data->img.pxl_ptr = mlx_get_data_addr(data->img.address, &data->img.bpp, \
		&data->img.line_len, &data->img.endian);
	if (!data->img.pxl_ptr)
		return (close_win(data), 1);
	view_definition(data);
	map_converter(data);
	draw_map(data);
	mlx_key_hook(data->win, key_input, data);
	mlx_mouse_hook(data->win, mouse_input, data);
	mlx_hook(data->win, 17, 0L, close_win, data);
	mlx_loop(data->mlx);
	return (0);
}

int	close_win(t_meta *data)
{
	get_free(data);
	if (data->img.address)
		mlx_destroy_image(data->mlx, data->img.address);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

void	get_free(t_meta *data)
{
	int	j;

	j = (-1);
	while (++j < data->map.height)
	{
		if (data->points3d[j])
			free(data->points3d[j]);
		if (data->points2d[j])
			free(data->points2d[j]);
	}
	if (data->points3d)
		free(data->points3d);
	if (data->points2d)
		free(data->points2d);
	if (data->map_path)
		free(data->map_path);
}
int	check_format(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (!(ft_strnstr(path, ".fdf", len)))
		return (1);
	if (ft_strncmp(&path[len - 4], ".fdf", 4))
		return (1);
	len -= 4;
	while (len-- > 0)
	{
		if (path[len] == '.')
			return (1);
		if (path[len] == '/')
			return (0);
	}
	return (0);
}
