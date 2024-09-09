/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:43:25 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/09 10:14:51 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "define.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>

int		main(int ac, char **av);
void	set_window(t_meta *data);
int		map_definition(int fd, t_meta *data);
void	view_definition(t_meta *data);
void	set_extremum(t_point **tab, t_map *map);
int		start(t_meta *data);
void	get_free(t_meta *data);
int		check_format(char *path);
int		key_input(int keycode, t_meta *data);
int		mouse_input(int mousecode, int x, int y, t_meta *data);
int		close_win(t_meta *data);
void	new_render(t_meta *data);
void	handle_altitude(int keycode, t_meta *data);
t_point	**map_malloc(t_meta *data);
void	map_reader(int fd, t_point **tab);
int		color_handler(const char *temp_z, t_point *cell);
int		map_converter(t_meta *data);
int		draw_map(t_meta *data);
void	draw_line(t_point start, t_point end, t_meta *data);
void	tool_init(t_point start, t_point end, t_draw_tool *tools);
void	put_pixel(t_meta *data, t_point point, int color);
void	tracer1(t_point start, t_point end, t_draw_tool *tools, t_meta *data);
void	tracer2(t_point start, t_point end, t_draw_tool *tools, t_meta *data);
int		color_set(t_point point, t_meta *data);
int		color_pick(t_point start, t_point end, t_draw_tool *tools);
void	decode_color(int color, t_rgb *color_code);
int		color_mix(int l1, int l2, float percent);
int		ortho_render(t_meta *data);

#endif
