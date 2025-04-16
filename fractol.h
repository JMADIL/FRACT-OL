/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:00:14 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/16 14:38:03 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include "minilibx_opengl_20191021/mlx.h"
# include <math.h>
#include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

/* Black & White */
# define BLACK 0x000000
# define WHITE 0xFFFFFF

/* Psychedelic Color Gradients (for animation) */
# define PSYCH_GRADIENT_1 0xFF00FF

// structs
typedef struct s_map_range
{
	double		start;
	double		end;
}				t_map_range;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}				t_img;
typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;
typedef struct s_fract
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		*fractal_name;
	t_map_range	range1;
	t_map_range	range2;
	int			iterations;
	double		escaped;
	double		zoom;
	double		julia_x;
	double		julia_y;

}				t_fract;

// events
int				key_handler(int keycode, t_fract *fractal);
int				mouse_handler(int button, int x, int y, t_fract *fractal);
int				close_handler(t_fract *fractal);

// math functions
double			rescale_the_map(double value, double new_max, double new_min,
					double old_max);
t_complex		motatabiqa_hama(t_complex z);
t_complex		complex_sum(t_complex z1, t_complex z2);

// fractol funs
void			init_fractal(t_fract *fractal);
void			fractal_render(t_fract *fractal);

// libc-functions
void			ft_putchar_fd(char c, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
double			atoi_double(char *str);

// helper struct

typedef struct s_variables
{
	double		integer;
	double		fractional;
	int			s;
	int			i;

}				t_variables;

#endif