/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:01:25 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/05 12:38:12 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_set(t_point point, t_meta *data)
{
	if (point.color != 0)
		return (point.color);
	if (point.z < data->map.min / 2)
		return (BLUE);
	else if (point.z < 0)
		return (SKYBLUE);
	else if (point.z > (0.6 * (data->map.max)))
		return (SIENNA);
	else if (point.z > (data->map.max * 0.35))
		return (GOLDENROD);
	else
		return (FORESTGREEN);
}

int	color_pick(t_point start, t_point end, t_draw_tool *tools)
{
	float	percent;
	t_rgb	start_color;
	t_rgb	end_color;
	t_rgb	curent_color;

	percent = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2)) \
		/ sqrt((pow((tools->dx / 2), 2) + pow((tools->dy / 2), 2)));
	decode_color(start.color, &start_color);
	decode_color(end.color, &end_color);
	curent_color.r = color_mix(start_color.r, end_color.r, percent);
	curent_color.g = color_mix(start_color.g, end_color.g, percent);
	curent_color.b = color_mix(start_color.b, end_color.b, percent);
	return (curent_color.r << 16 | curent_color.g << 8 \
		| curent_color.b);
}

void	decode_color(int color, t_rgb *color_code)
{
	color_code->r = (color >> 16) & 0xFF;
	color_code->g = (color >> 8) & 0xFF;
	color_code->b = color & 0xFF;
}

int	color_mix(int l1, int l2, float percent)
{
	return ((int)(l2 + percent * (l1 - l2)));
}
