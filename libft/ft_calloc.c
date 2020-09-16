/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:21:43 by student           #+#    #+#             */
/*   Updated: 2020/05/27 19:25:41 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#	define MAX (size_t)~0

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((size && MAX / size < count) || (count && MAX / count < size))
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (0);
	ft_memset(arr, '\0', count * size);
	return (arr);
}
