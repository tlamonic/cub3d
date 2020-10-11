/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:27:32 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:27:33 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (0);
	if (!(str = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (0);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat(str, s1, -1);
	ft_strlcat(str, s2, -1);
	return (str);
}
