/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:21:35 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/29 18:19:04 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoabase_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*negative = 1;
	}
	else
		*negative = 0;
}

static int	get_num_len(int n, int neg, unsigned int base)
{
	int len;

	len = 2;
	while ((n = n / base))
		len++;
	return (len + neg);
}

char		*ft_itoabase(int n, unsigned int base)
{
	int		len;
	int		negative;
	int		remainder;
	char	*str;

	itoabase_isnegative(&n, &negative);
	len = get_num_len(n, negative, base);
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		remainder = n % base;
		str[len] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
		n = n / base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
