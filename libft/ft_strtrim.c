/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:27:09 by student           #+#    #+#             */
/*   Updated: 2020/05/19 15:25:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j - 1]) && j - 1)
		j--;
	str = (char*)malloc(j - i + 1);
	if (!str)
		return (0);
	str[j - i] = '\0';
	while (j - i)
	{
		str[j - i - 1] = s1[j - 1];
		j--;
	}
	return (str);
}
