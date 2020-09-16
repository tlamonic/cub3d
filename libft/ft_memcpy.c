/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:23:57 by student           #+#    #+#             */
/*   Updated: 2020/05/27 19:28:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	if (!dst && !src)
		return (0);
	i = 0;
	str = (unsigned char*)dst;
	str1 = (unsigned char*)src;
	while (i < n)
	{
		str[i] = str1[i];
		i++;
	}
	return (dst);
}
