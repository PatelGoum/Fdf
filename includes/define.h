/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:17 by maguerin          #+#    #+#             */
/*   Updated: 2024/09/09 10:43:33 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WIDTH 1500
# define HEIGHT 1200
# define BLUE 0x4169E1
# define SKYBLUE 0x87ceeb
# define SIENNA 0xa0522d
# define GOLDENROD 0xdaa520
# define FORESTGREEN 0x228b22
# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define DOWN 65364
# define UP 65362
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_O 111

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
}	t_point;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map
{
	int		width;
	int		height;
	int		min;
	int		max;
	int		angle;
	float	altitude;
	int		zoom;
	int		mov_x;
	int		mov_y;
}	t_map;

typedef struct s_draw_tool
{
	float	error_x;
	float	error_y;
	float	dx;
	float	dy;
	int		x_incr;
	int		y_incr;
	int		color;
}	t_draw_tool;

typedef struct s_img
{
	void	*address;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_meta
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	char	*map_path;
	t_img	img;
	t_point	**points2d;
	t_point	**points3d;
	t_map	map;
}	t_meta;

#endif
