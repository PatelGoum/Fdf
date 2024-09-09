/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:01:08 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/09 10:19:25 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ortho_converter(t_meta *data)
{
	int	i;
	int	j;

	j = (-1);
	while (++j < data->map.height)
	{
		i = (-1);
		while (++i < data->map.width)
		{
			data->points2d[j][i].x = 50 + data->map.zoom \
				* data->points3d[j][i].x;
			data->points2d[j][i].y = 50 + data->map.zoom \
				* data->points3d[j][i].y ;
			data->points2d[j][i].z = data->points3d[j][i].z;
			data->points2d[j][i].color = color_set(data->points3d[j][i], data);
		}
	}
}

int	ortho_render(t_meta *data)
{
	mlx_clear_window(data->mlx, data->win);
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
	ortho_converter(data);
	draw_map(data);
	return (0);
}
