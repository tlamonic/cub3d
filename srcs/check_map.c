/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:53:33 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/08 14:56:02 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map(char *av)
{
	const char	*st = ".cub";
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (av[i])
		i++;
	i -= 4;
	if (!av[i - 1])
		return (-1);
	while (av[i] && st[j] && av[i] == st[j])
	{
		i++;
		j++;
	}
	if (av[i] || st[j])
		return (-1);
	return (1);
}
