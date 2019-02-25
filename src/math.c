/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:13:12 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 14:13:14 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Multiplying complex numbers goes like this:
** (1 + 2i)(3 + 4i)
** (1*3 + 1*4i + 2i*3 + 2i*4i)
** (3 + 4i + 6i + 8i^2)
** (3 + 10i + 8i^2)
** (3 + 10i + 8 * -1) i^2 becomes -1
** (3 - 8 + 10i)
** (-5 + 10i)
*/

static t_point	cn_sqrt(t_point a)
{
	double	temp_x;
	double	temp_y;

	temp_x = (a.x * a.x) + (a.y * a.y * -1);
	temp_y = (a.x * a.y) + (a.y * a.x);
	a.x = temp_x;
	a.y = temp_y;
	return (a);
}

int				julia(t_point z, t_point c, int max_iteration)
{
	int		i;

	i = 0;
	while ((z.x * z.x + z.y * z.y < 4) && i < max_iteration)
	{
		z = cn_sqrt(z);
		z.x += c.x;
		z.y += c.y;
		i++;
	}
	return (i);
}

int				mandelbrot(t_point z, int max_iteration)
{
	t_point	c;
	int		i;

	c = z;
	i = 0;
	while ((z.x * z.x + z.y * z.y < 4) && i < max_iteration)
	{
		z = cn_sqrt(z);
		z.x += c.x;
		z.y += c.y;
		i++;
	}
	return (i);
}

int				burning_ship(t_point z, int max_iteration)
{
	t_point	c;
	int		i;

	c = z;
	i = 0;
	while ((z.x * z.x + z.y * z.y < 4) && i < max_iteration)
	{
		z = cn_sqrt(z);
		z.x = fabs(z.x + c.x);
		z.y = fabs(z.y) + c.y;
		i++;
	}
	return (i);
}

int				tricorn(t_point z, int max_iteration)
{
	t_point	c;
	int		i;

	c = z;
	i = 0;
	while ((z.x * z.x + z.y * z.y < 4) && i < max_iteration)
	{
		z = cn_sqrt(z);
		z.x = z.x + c.x;
		z.y = (z.y * -1) + c.y;
		i++;
	}
	return (i);
}
