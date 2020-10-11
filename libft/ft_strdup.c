/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:27:16 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:27:17 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(s1 = malloc(sizeof(char) * i + 1)))
		return (0);
	j = 0;
	while (j <= i)
	{
		s1[j] = src[j];
		j++;
	}
	return (s1);
}
