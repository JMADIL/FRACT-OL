/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:29:18 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/16 14:48:14 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_error(void)
{
	write(2, "Invalide param\n", 15);
	exit(1);
}

static double	fractional_part(char *str, int i)
{
	double	fractio_part;
	double	pow;

	pow = 1;
	fractio_part = 0;
	i++;
	if (str[i] == '\0' || str[i] == ' ')
		ft_error();
	while (str[i] <= '9' && str[i] >= '0')
	{
		pow /= 10;
		fractio_part = fractio_part + (str[i] - 48) * pow;
		i++;
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		ft_error();
	return (fractio_part);
}

static int	check_if(double i)
{
	if (i > 2 || i < -2)
		return (0);
	return (1);
}

static void	check_if_sign(char c)
{
	if (c == '-' || c == '+')
		ft_error();
	return ;
}

double	atoi_double(char *str)
{
	t_variables	vr;

	vr.integer = 0;
	vr.fractional = 0;
	vr.i = 0;
	vr.s = 1;
	while (str[vr.i] == ' ' || (str[vr.i] >= 9 && str[vr.i] <= 13))
		vr.i++;
	if (str[vr.i] == '-')
	{
		vr.s *= -1;
		vr.i++;
		check_if_sign(str[vr.i]);
	}
	while (str[vr.i] >= '0' && str[vr.i] <= '9')
	{
		vr.integer = vr.integer * 10 + (str[vr.i++] - '0');
		if (vr.integer > 2 || vr.integer < -2)
			ft_error();
	}
	if (str[vr.i] == '.')
		vr.fractional = fractional_part(str, vr.i);
	if (!(check_if((vr.integer + vr.fractional) * vr.s)))
		ft_error();
	return ((vr.integer + vr.fractional) * vr.s);
}
