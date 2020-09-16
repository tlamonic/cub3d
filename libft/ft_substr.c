/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:27:19 by student           #+#    #+#             */
/*   Updated: 2020/05/25 16:39:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		j;

	if (!s)
		return (0);
	j = 0;
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	else if (start + len > (unsigned)ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char*)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (j != len && s[j])
	{
		str[j] = s[start];
		start++;
		j++;
	}
	str[len] = '\0';
	return (str);
}
