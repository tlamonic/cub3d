/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:22:30 by student           #+#    #+#             */
/*   Updated: 2020/05/27 15:57:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getsize(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_getsize(n);
	if (!(str = (char*)malloc((size + 1) * sizeof(char))))
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	i = size - 1;
	while (n)
	{
		str[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
	str[size] = '\0';
	return (str);
}
