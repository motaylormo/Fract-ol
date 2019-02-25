/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:34:09 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 14:34:12 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x <= IMG_SIZE && y >= 0 && y <= IMG_SIZE)
	{
		*(int*)(img->data + ((x + (y * IMG_SIZE)) * img->bpp)) = color;
	}
}

static int		get_color(double i, double max_i)
{
	return ((i / max_i) * 0xFFFFFF);
}

static t_point	scale_point(t_window *window, int x, int y)
{
	t_point	point;

	point.x = 2.0 * (x - window->center->x) / (0.5 * window->zoom * IMG_SIZE);
	point.y = 2.0 * (y - window->center->y) / (0.5 * window->zoom * IMG_SIZE);
	return (point);
}

static int (*g_fractals[])(t_point, int) =
{
	['m'] = mandelbrot,
	['b'] = burning_ship,
	['t'] = tricorn
};

void			calc_row(t_window *window, int x)
{
	t_point	z;
	t_point	c;
	int		point_i;
	int		y;

	y = 0;
	while (y < IMG_SIZE)
	{
		z = scale_point(window, x, y);
		if (window->curr_frac == 'j')
		{
			c = (t_point){
				(2.0 * (window->mouse->x - IMG_SIZE / 2)) / (IMG_SIZE * 0.5),
				(2.0 * (window->mouse->y - IMG_SIZE / 2)) / (IMG_SIZE * 0.5)};
			point_i = julia(z, c, window->iters);
		}
		else
			point_i = g_fractals[window->curr_frac](z, window->iters);
		img_pixel_put(window->img, x, y, get_color(point_i, window->iters));
		y++;
	}
}
