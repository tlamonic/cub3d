/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:30:56 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/07 17:30:58 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	unsigned int	i;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	while (u1[i] != 0 && u2[i] != 0 && u1[i] == u2[i] && i < n)
		i++;
	if (n == i)
		return (0);
	return (u1[i] - u2[i]);
}
