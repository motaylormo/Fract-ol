/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:05:18 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 18:16:58 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_image	*create_image(t_window *window)
{
	t_image	*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(window->mlx_ptr, IMG_SIZE, IMG_SIZE);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->size_line, &image->endian);
	image->bpp /= 8;
	return (image);
}

static t_point	*create_point(int x, int y)
{
	t_point	*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_window		*create_window(char param)
{
	t_window	*window;

	window = (t_window*)malloc(sizeof(t_window));
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			IMG_SIZE, IMG_SIZE + TEXT_BAR, WINDOW_TITLE);
	window->img = create_image(window);
	window->mouselock = 0;
	window->mouse = create_point(0, 0);
	window->center = create_point(IMG_SIZE / 2, IMG_SIZE / 2);
	window->zoom = 1;
	window->curr_frac = param;
	window->iters = START_ITERS;
	return (window);
}
