/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:25:59 by student           #+#    #+#             */
/*   Updated: 2020/05/21 23:22:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		j;

	if (!dst || !src)
		return (0);
	i = 0;
	j = 0;
	while (dst[i] != '\0' && size > i)
		i++;
	if (size < i + 1)
		return (size + ft_strlen(src));
	while (src[j])
	{
		if (size > i + j + 1)
			dst[i + j] = src[j];
		j++;
	}
	if (size > i + j + 1)
		dst[i + j] = '\0';
	else
		dst[size - 1] = '\0';
	return (i + j);
}
