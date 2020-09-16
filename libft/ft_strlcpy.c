/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:26:09 by student           #+#    #+#             */
/*   Updated: 2020/05/11 17:40:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (src[i])
	{
		if (size > i + 1)
			dst[i] = src[i];
		i++;
	}
	if (size > i + 1)
		dst[i] = '\0';
	else
		dst[size - 1] = '\0';
	return (i);
}
