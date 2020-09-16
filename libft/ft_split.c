/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:21:15 by student           #+#    #+#             */
/*   Updated: 2020/05/27 15:58:54 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	splits(char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((i > 0 && s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
			len++;
		i++;
	}
	return (len);
}

static void		freearr(char **str, int len)
{
	while (len > 0)
	{
		free(str[len]);
		len--;
	}
	free(str);
}

static void		fillarr(char **str, const char *s, char c, int len)
{
	int i;
	int l;
	int j;

	i = 0;
	l = 0;
	while (l < len)
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] && s[i + j] != c && s[i + j])
			j++;
		if (!(str[l] = ft_calloc(sizeof(char), j + 1)))
		{
			freearr(str, l);
			return ;
		}
		j = 0;
		while (s[i] && s[i] != c && s[i])
			str[l][j++] = s[i++];
		str[l][j] = '\0';
		l++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		len;

	if (!s)
		return (NULL);
	len = splits(s, c);
	if (!(str = ft_calloc(sizeof(char *), len + 1)))
		return (NULL);
	fillarr(str, s, c, len);
	if (!str)
		return (0);
	str[len] = 0;
	return (str);
}
