/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:59:52 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/14 15:48:05 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fract	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)))
	{
		fractal.fractal_name = av[1];
		init_fractal(&fractal);
	}
	else if ((ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.fractal_name = av[1];
		fractal.julia_x = atoi_double(av[2]);
		fractal.julia_y = atoi_double(av[3]);
		init_fractal(&fractal);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol <fractal_name>\n", 2);
		ft_putstr_fd("Available fractals:\n", 2);
		ft_putstr_fd("  mandelbrot     - Classic Mandelbrot set\n", 2);
		ft_putstr_fd("  julia          - Julia set\n", 2);
		ft_putstr_fd("Example:\n", 2);
		ft_putstr_fd("  ./fractol mandelbrot\n", 2);
	}
}
