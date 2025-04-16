/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:59:39 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/16 14:48:37 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fract *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fract *fractal)
{
	if (keycode == 53)
		close_handler(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fract *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 1.1;
	}
	else if (button == 5)
	{
		fractal->zoom /= 1.1;
	}
	fractal_render(fractal);
	return (0);
}
