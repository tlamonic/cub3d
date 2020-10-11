/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:28:36 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:28:38 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	int flag;

	flag = 0;
	while (*str)
	{
		if (*str == ch)
			flag = 1;
		str++;
	}
	while (flag == 1)
	{
		if (*str == ch)
			return ((char *)str);
		str--;
	}
	if (ch == '\0')
		return ((char *)str);
	return (0);
}
