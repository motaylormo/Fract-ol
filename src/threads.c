/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:53:10 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 13:54:34 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*delegate_threads(void *param)
{
	t_thread	*wrapper;
	int			x;

	wrapper = param;
	x = wrapper->i;
	while (x < IMG_SIZE)
	{
		calc_row(wrapper->window, x);
		x += THREAD_NUM;
	}
	return (NULL);
}

int			calc_screen(t_window *window)
{
	t_thread	array[THREAD_NUM];
	int			i;

	ft_bzero(window->img->data, IMG_SIZE * IMG_SIZE * window->img->bpp);
	i = 0;
	while (i < THREAD_NUM)
	{
		array[i].i = i;
		array[i].window = window;
		pthread_create(&(array[i]).thread, NULL, delegate_threads, &array[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		pthread_join(array[i].thread, NULL);
		i++;
	}
	display_image(window);
	return (1);
}
