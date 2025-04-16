/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:04:06 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/16 14:52:14 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

static void	is_it_julia_or_mandel(t_complex *c, t_complex *z, t_fract *fractal)
{
	if (!ft_strncmp(fractal->fractal_name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fract *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = ((rescale_the_map(x, 2, -2, WIDTH)) * fractal->zoom);
	z.y = ((rescale_the_map(y, -2, 2, HEIGHT)) * fractal->zoom);
	is_it_julia_or_mandel(&c, &z, fractal);
	while (i < fractal->iterations)
	{
		z = complex_sum(motatabiqa_hama(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escaped)
		{
			color = rescale_the_map(i, PSYCH_GRADIENT_1, BLACK,
					fractal->iterations);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fract *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0,
		0);
}
