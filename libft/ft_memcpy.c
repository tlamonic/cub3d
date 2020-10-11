/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:26:01 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:26:02 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sr;

	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	ds = (char *)dest;
	sr = (char *)src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (ds);
}
