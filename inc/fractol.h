/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:10:04 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 18:46:04 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** <fcntl.h> is for open
** <unistd.h> is for read, write, & close
** <stdlib.h> is for malloc, free, & exit
** <math.h> is allowed for this project
** "mlx.h" and "libft.h" are for the miniLibX and libft libraries
** <pthread.h> is allowed under
** 			"You are allowed to use other functions to complete the bonus part
**			as long as their use is justified"
*/
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"
# include <pthread.h>

# define WINDOW_TITLE "mtaylor's fract'ol"
# define THREAD_NUM 6
# define START_ITERS 100
# define IMG_SIZE 800
# define TEXT_BAR 120
# define TEXT_COLOR 0xFFFFFF
# define SUBBOX_SIZE 275

# define ZOOM_INC 0.1
# define MOVE_INC 7
# define ITER_INC 10

# define CLICK 1
# define SCROLL_DOWN 4
# define SCROLL_UP 5

# define ESC_KEY 53
# define SPACE_BAR 49
# define RETURN_KEY 36
# define MINUS_KEY 27
# define PLUS_KEY 24
# define ARROW_KEY(c) (c >= 123 && c <= 126)
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;
	int			curr_frac;
	int			iters;
	t_point		*center;
	double		zoom;
	int			mouselock;
	t_point		*mouse;
}				t_window;

typedef struct	s_thread
{
	pthread_t	thread;
	t_window	*window;
	int			i;
}				t_thread;

t_window		*create_window(char param);
void			display_image(t_window *window);
int				calc_screen(t_window *window);
void			calc_row(t_window *window, int x);

/*
** Functions to handle user actions
*/
int				mouse_click(int button, int x, int y, t_window *window);
int				key_press(int keycode, t_window *window);
int				mouse_move(int x, int y, t_window *window);
int				x_button(void);

/*
** The fractal math, in math.c
*/
int				julia(t_point z, t_point c, int max_iteration);
int				mandelbrot(t_point z, int max_iteration);
int				burning_ship(t_point z, int max_iteration);
int				tricorn(t_point z, int max_iteration);

#endif
