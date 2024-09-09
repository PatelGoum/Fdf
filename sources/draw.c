/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:52:37 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/09 10:20:18 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point start, t_point end, t_meta *data)
{
	t_draw_tool	tools;

	tool_init(start, end, &tools);
	if (tools.error_x > tools.error_y)
		tracer1(start, end, &tools, data);
	else
		tracer2(start, end, &tools, data);
}

void	tool_init(t_point start, t_point end, t_draw_tool *tools)
{
	if (start.x > end.x)
	{
		tools->x_incr = -1;
		tools->error_x = start.x - end.x;
	}
	else
	{
		tools->x_incr = 1;
		tools->error_x = end.x - start.x;
	}
	if (start.y > end.y)
	{
		tools->y_incr = -1;
		tools->error_y = start.y - end.y;
	}
	else
	{
		tools->y_incr = 1;
		tools->error_y = end.y - start.y;
	}
	tools->dx = 2 * tools->error_x;
	tools->dy = 2 * tools->error_y;
}

void	tracer1(t_point start, t_point end, t_draw_tool *tools, t_meta *data)
{
	int	i;

	i = (-1);
	while (++i <= (tools->dx / 2))
	{
		tools->color = color_pick(start, end, tools);
		put_pixel(data, start, tools->color);
		start.x += tools->x_incr;
		tools->error_x -= tools->dy;
		if (tools->error_x < 0)
		{
			start.y += tools->y_incr;
			tools->error_x += tools->dx;
		}
	}
}

void	tracer2(t_point start, t_point end, t_draw_tool *tools, t_meta *data)
{
	int	i;

	i = (-1);
	while (++i < (tools->dy / 2))
	{
		tools->color = color_pick(start, end, tools);
		put_pixel(data, start, tools->color);
		start.y += tools->y_incr;
		tools->error_y -= tools->dx;
		if (tools->error_y < 0)
		{
			start.x += tools->x_incr;
			tools->error_y += tools->dy;
		}
	}
}

void	put_pixel(t_meta *data, t_point point, int color)
{
	int	offset;
	int	x;
	int	y;

	x = point.x;
	y = point.y;
	if (point.x < 0 || point.y < 0 || point.x >= data->win_width || point.y >= data->win_height)
		return ;
	offset = x * data->img.bpp / 8 + y * data->img.line_len ;
	*(unsigned int *)(offset + data->img.pxl_ptr) = color;
}
