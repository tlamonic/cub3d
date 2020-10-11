/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:22:47 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:22:48 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_minint(int n, char *s)
{
	if (n == -2147483648)
	{
		s[1] = '2';
		n = -147483648;
	}
	return (n);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_intlen(n);
	if (!(str = malloc(sizeof(char ) * (i + 1))))
		return (NULL);
	ft_bzero(str, i + 1);
	n = ft_minint(n, str);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
