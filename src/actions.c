/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:33:59 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 14:34:01 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_click(int button, int x, int y, t_window *window)
{
	double	old_zoom;

	y -= TEXT_BAR;
	if (button == SCROLL_DOWN || button == SCROLL_UP)
	{
		old_zoom = window->zoom;
		window->zoom += window->zoom *
			((button == SCROLL_DOWN) ? ZOOM_INC : -ZOOM_INC);
		if (window->zoom * IMG_SIZE < 1.0)
			window->zoom = 1.0 / IMG_SIZE;
		x -= IMG_SIZE / 2;
		y -= IMG_SIZE / 2;
		window->center->x -= (x * window->zoom) - (x * old_zoom);
		window->center->y -= (y * window->zoom) - (y * old_zoom);
	}
	else if (button == CLICK && window->curr_frac == 'j')
	{
		window->mouselock = (window->mouselock == 0) ? 1 : 0;
		window->mouse->x = x;
		window->mouse->y = y;
	}
	return (1);
}

static char	g_next_frac[] = {
	['j'] = 'm',
	['m'] = 'b',
	['b'] = 't',
	['t'] = 'j'
};

static double	g_increment[] = {
	[ARROW_UP] = MOVE_INC,
	[ARROW_DOWN] = -MOVE_INC,
	[ARROW_LEFT] = MOVE_INC,
	[ARROW_RIGHT] = -MOVE_INC,
	[PLUS_KEY] = ITER_INC,
	[MINUS_KEY] = -ITER_INC
};

int		key_press(int keycode, t_window *window)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == SPACE_BAR)
		window->curr_frac = g_next_frac[window->curr_frac];
	if (keycode == ARROW_UP || keycode == ARROW_DOWN)
		window->center->y += g_increment[keycode];
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		window->center->x += g_increment[keycode];
	if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		window->iters += g_increment[keycode];
	if (keycode == RETURN_KEY)
	{
		window->center->x = IMG_SIZE / 2;
		window->center->y = IMG_SIZE / 2;
		window->iters = START_ITERS;
		window->zoom = 1;
	}
	return (1);
}

int		mouse_move(int x, int y, t_window *window)
{
	y -= TEXT_BAR;
	if (window->curr_frac == 'j' && window->mouselock == 0)
	{
		window->mouse->x = x;
		window->mouse->y = y;
	}
	return (1);
}

int		x_button(void)
{
	exit(0);
	return (0);
}
