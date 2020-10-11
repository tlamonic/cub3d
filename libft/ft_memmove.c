/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:26:07 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:26:09 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ds;
	const char	*sr;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = -1;
	ds = (char *)dest;
	sr = (char *)src;
	if (ds > sr)
		while (++i < n)
			ds[n - i - 1] = sr[n - i - 1];
	else
		while (++i < n)
			ds[i] = sr[i];
	return (ds);
}
