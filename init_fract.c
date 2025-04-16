/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:27:50 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/14 15:32:31 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_error(void)
{
	perror("Error: Memory allocation failed (malloc)\n");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fract *fractal)
{
	fractal->escaped = 4;
	fractal->iterations = 51;
	fractal->zoom = 1.0;
}

void	events_init(t_fract *fractal)
{
	mlx_hook(fractal->win, 2, 0, key_handler, fractal);
	mlx_hook(fractal->win, 4, 0, mouse_handler, fractal);
	mlx_hook(fractal->win, 17, 0, close_handler, fractal);
	mlx_loop(fractal->mlx);
}

void	init_fractal(t_fract *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		handle_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			fractal->fractal_name);
	if (fractal->win == NULL)
	{
		free(fractal->mlx);
		handle_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		free(fractal->mlx);
		handle_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	data_init(fractal);
	fractal_render(fractal);
	events_init(fractal);
	mlx_loop(fractal->mlx);
}
