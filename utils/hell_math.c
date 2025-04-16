/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:43:54 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/12 10:47:32 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	rescale_the_map(double value, double new_max, double new_min,
		double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (value - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex	motatabiqa_hama(t_complex z)
{
	t_complex	results;

	results.x = z.x * z.x - z.y * z.y;
	results.y = 2 * z.x * z.y;
	return (results);
}

t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	results;

	results.x = z1.x + z2.x;
	results.y = z1.y + z2.y;
	return (results);
}
