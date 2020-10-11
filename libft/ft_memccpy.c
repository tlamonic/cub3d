/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:23:36 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:23:38 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ds;
	unsigned char	*sr;
	unsigned char	cc;

	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	cc = (unsigned char)c;
	ds = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (i < n)
	{
		ds[i] = sr[i];
		if (ds[i] == cc)
			return (ds + 1 + i);
		i++;
	}
	return (NULL);
}
