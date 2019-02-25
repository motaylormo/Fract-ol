/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:28:35 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 16:32:00 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	while (*s)
		s++;
	if (c == '\0' && *s == '\0')
		return ((char*)s);
	s--;
	while (len--)
	{
		if (*s == c)
			return ((char*)s);
		s--;
	}
	return (0);
}
