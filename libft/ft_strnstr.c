/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:26:57 by student           #+#    #+#             */
/*   Updated: 2020/05/23 18:10:24 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *st, size_t len)
{
	size_t	i;
	int		in;

	if (ft_strlen(st) == 0)
		return ((char*)s);
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		in = 0;
		while (s[i + in] == st[in] && st[in] != '\0' && len > i + in)
			in++;
		if (!st[in])
			return ((char*)(s + i));
		i++;
	}
	return (0);
}
