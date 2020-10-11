/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:28:44 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:28:45 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlentrim(int i, int j)
{
	int k;

	k = 0;
	while (i < j + 1)
	{
		k++;
		i++;
	}
	return (k);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL)
		return (NULL);
	j = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j && ft_strchr(set, s1[j]))
		j--;
	if (!(str = malloc(sizeof(char ) * ft_strlentrim(i, j) + 1)))
		return (NULL);
	k = 0;
	while (i < j + 1)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
