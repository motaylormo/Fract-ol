/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:08:15 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 22:03:08 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*case_convert(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A') + 'a';
		i++;
	}
	while (i-- > 0 && str[i] == ' ')
		str[i] = '\0';
	while (*str == ' ')
		str++;
	return (str);
}

static int	read_param(char *str, char *str2)
{
	str = case_convert(str);
	if (ft_strnequ(str, "julia", 5))
		return ('j');
	if (ft_strnequ(str, "mandelbrot", 10))
		return ('m');
	if (ft_strnequ(str, "burning ship", 12) ||
			(ft_strequ(str, "burning") && ft_strequ(str2, "ship")))
		return ('b');
	if (ft_strnequ(str, "tricorn", 7))
		return ('t');
	ft_putstr("Type the name of the escape-time fractal you want:\n");
	ft_putstr("\"julia\", \"mandelbrot\", \"burning ship\", or \"tricorn\"\n");
	return (0);
}

int			main(int argc, char **argv)
{
	t_window	*window;
	char		param;

	param = read_param((argc > 1) ? argv[1] : "",
						(argc > 2) ? argv[2] : "");
	if (param == 0)
		return (0);
	window = create_window(param);
	calc_screen(window);
	mlx_hook(window->win_ptr, 17, 0, x_button, NULL);
	mlx_hook(window->win_ptr, 6, 0, mouse_move, window);
	mlx_mouse_hook(window->win_ptr, mouse_click, window);
	mlx_key_hook(window->win_ptr, key_press, window);
	mlx_loop_hook(window->mlx_ptr, &calc_screen, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}
