/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:34:31 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/09 10:42:00 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_input(int keycode, t_meta *data)
{
	if (keycode == ESC)
		return (close_win(data), 0);
	else if (keycode == RIGHT)
		data->map.angle -= 10;
	else if (keycode == LEFT)
		data->map.angle += 10;
	else if (keycode == DOWN || keycode == UP)
		handle_altitude(keycode, data);
	else if (keycode == KEY_A)
		data->map.mov_x -= data->win_width / 20;
	else if (keycode == KEY_D)
		data->map.mov_x += data->win_width / 20;
	else if (keycode == KEY_W)
		data->map.mov_y -= data->win_height / 20;
	else if (keycode == KEY_S)
		data->map.mov_y += data->win_height / 20;
	else if (keycode == KEY_O)
		return (ortho_render(data));
	else if (keycode)
		return (0);
	mlx_clear_window(data->mlx, data->win);
	new_render(data);
	return (0);
}

int	mouse_input(int mousecode, int x, int y, t_meta *data)
{
	(void) x;
	(void) y;
	if (mousecode == 4)
	{
		data->map.zoom *= 1.5;
		if ((data->map.zoom) > 1000)
			data->map.zoom = 1000;
	}
	else if (mousecode == 5)
	{
		data->map.zoom /= 1.5;
		if ((data->map.zoom) < 2)
			data->map.zoom = 2;
	}
	else if (mousecode)
		return (0);
	mlx_clear_window(data->mlx, data->win);
	new_render(data);
	return (0);
}

void	new_render(t_meta *data)
{
	if (data->img.address)
		mlx_destroy_image(data->mlx, data->img.address);
	data->img.address = mlx_new_image(data->mlx, data->win_width, \
		data->win_height);
	if (!data->img.address)
		close_win(data);
	data->img.pxl_ptr = mlx_get_data_addr(data->img.address, &data->img.bpp, \
	&data->img.line_len, &data->img.endian);
	if (!data->img.pxl_ptr)
		close_win(data);
	map_converter(data);
	draw_map(data);
}

void	handle_altitude(int keycode, t_meta *data)
{
	if (keycode == DOWN)
		data->map.altitude = data->map.altitude / 1.2;
	else if (keycode == UP)
	{
		data->map.altitude = data->map.altitude * 1.2;
		if (data->map.altitude > 100)
			data->map.altitude = 100;
	}
}
