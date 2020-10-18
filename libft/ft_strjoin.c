/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:30:25 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/18 13:45:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!(res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char))))
		return (0);
	while (s1[j])
		res[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res);
}
