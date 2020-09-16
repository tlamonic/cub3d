/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:27:02 by student           #+#    #+#             */
/*   Updated: 2020/05/25 17:09:15 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	str = (char*)s;
	i = ft_strlen(s);
	while (i > -1)
	{
		if (str[i] == (char)c)
			return ((char*)&str[i]);
		i--;
	}
	return (0);
}
