/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:04:32 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/23 15:08:55 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_str(double n, int precision, double *div)
{
	char	*str;
	int		num_width;

	num_width = (n < 0) ? 2 : 1;
	while ((*div * 10 <= n))
	{
		*div *= 10;
		num_width++;
	}
	if (precision > 0)
		num_width += precision + 1;
	str = (char*)ft_memalloc(sizeof(char) * (num_width + 1));
	ft_bzero(str, num_width);
	return (str);
}

char	*ft_dtoa(double n, int precision)
{
	char			*str;
	double			div;
	unsigned int	digit;
	int				i;

	div = 1;
	str = make_str(n, precision, &div);
	i = 0;
	if (n < 0)
		str[i++] = -'-';
	while (div >= 1)
	{
		digit = n / div;
		n -= div * digit;
		div /= 10;
		str[i++] = digit + '0';
	}
	if (precision > 0)
		str[i++] = '.';
	while (precision--)
	{
		digit = n * 10;
		n = (n * 10) - digit;
		str[i++] = digit + '0';
	}
	return (str);
}
