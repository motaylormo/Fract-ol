/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:03:46 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/29 18:16:06 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*negative = 1;
	}
	else
		*negative = 0;
}

static int	get_num_len(int n, int neg)
{
	int len;

	len = 2;
	while ((n = n / 10))
		len++;
	return (len + neg);
}

char		*ft_itoa(int n)
{
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	itoa_isnegative(&n, &negative);
	len = get_num_len(n, negative);
	if ((str = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
