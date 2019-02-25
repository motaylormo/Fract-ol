/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:00:43 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 15:12:37 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define LETTER_WIDTH 10
#define MARGIN 10

static char	*g_frac_name[] = {
	['j'] = "Julia set",
	['m'] = "Mandelbrot set",
	['b'] = "Burning ship fractal",
	['t'] = "Tricorn fractal",
	['n'] = "Newton fractal",
	['l'] = "Lyapunov fractal"
};

static void	text_line(t_window *window, int x, int y, char *str)
{
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			MARGIN + x, (MARGIN / 2) + y, TEXT_COLOR, str);
}

static void	current_deets(t_window *window, int y_line)
{
	int		i;
	int		center;
	char	*num[2];
	char	*line[3];

	num[0] = ft_itoa(window->iters);
	num[1] = ft_dtoa(window->zoom, (window->zoom < 0.01) ? 3 : 2);
	line[0] = g_frac_name[window->curr_frac];
	line[1] = ft_strjoin("Iterations: ", num[0]);
	line[2] = ft_strjoin("Zoom: ", num[1]);
	i = 0;
	while (i < 3)
	{
		center = (IMG_SIZE - SUBBOX_SIZE) +
			((SUBBOX_SIZE - (ft_strlen(line[i]) * LETTER_WIDTH)) / 2);
		text_line(window, center, (i * y_line) +
				((TEXT_BAR - MARGIN) - (y_line * 3)) / 2, line[i]);
		i++;
	}
	free(line[1]);
	free(line[2]);
	free(num[0]);
	free(num[1]);
}

static char	*g_dirr_lines[] = {
	[0] = "Press the space bar to tab through the fractals",
	[1] = "Use '+' and '-' to change the iterations",
	[2] = "Use the mouse to scroll in and out",
	[3] = "Hit 'return' to reset everything",
	[4] = "Click to lock/unlock the mouse"
};

void		display_image(t_window *window)
{
	int	y_line;
	int	center;
	int	i;

	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->img->ptr, 0, TEXT_BAR);
	y_line = (TEXT_BAR - MARGIN) / ((window->curr_frac == 'j') ? 5 : 4);
	i = 0;
	while (i < ((window->curr_frac == 'j') ? 5 : 4))
	{
		center = ((IMG_SIZE - SUBBOX_SIZE - MARGIN * 4) -
				(ft_strlen(g_dirr_lines[i]) * LETTER_WIDTH)) / 2;
		text_line(window, center, i * y_line, g_dirr_lines[i]);
		i++;
	}
	current_deets(window, y_line);
}
