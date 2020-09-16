/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:23:34 by student           #+#    #+#             */
/*   Updated: 2020/05/27 12:36:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	if (!dst || !src)
		return (0);
	i = 0;
	str = (unsigned char*)dst;
	str1 = (unsigned char*)src;
	while (i < n && i <= ft_strlen(src))
	{
		*str = *str1;
		str++;
		str1++;
		i++;
		if (*(str - 1) == (unsigned char)c)
			return (str);
	}
	return (0);
}
