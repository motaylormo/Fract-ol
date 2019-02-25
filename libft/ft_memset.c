/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:07:53 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 15:46:00 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char character;
	unsigned char *str;

	character = c;
	str = b;
	while (len > 0)
	{
		*str = character;
		str++;
		len--;
	}
	return (b);
}
