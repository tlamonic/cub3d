/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:28:52 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:28:52 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlensub(char const *s, int start, int len)
{
	int	i;

	i = 0;
	while (s[start + i] && i < len)
		i++;
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned	int	min;
	unsigned	int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		if (!(str = ft_calloc(1, sizeof(char))))
			return (0);
		return (str);
	}
	min = ft_strlen(s) - start;
	if (min < len)
		len = min;
	i = ft_strlensub(s, start, len);
	if (!(str = ft_calloc(sizeof(char ), i + 1)))
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
