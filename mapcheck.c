/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:17:44 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:17:44 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkfirststr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("0SWEN2", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_out(char **arr, int i, int j)
{
	if (arr[i + 1][j] == ' ' || arr[i + 1][j] == '\0')
		return (1);
	if (arr[i - 1][j] == ' ' || arr[i - 1][j] == '\0')
		return (1);
	if (arr[i][j + 1] == ' ' || arr[i][j + 1] == '\0')
		return (1);
	if (arr[i][j - 1] == ' ' || arr[i][j - 1] == '\0')
		return (1);
	return (0);
}

int		checkinside(char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (ft_strchr("0SWEN2", arr[i][j]) && ft_out(arr, i, j) == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		checklast(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i - 1 >= 0)
		if (ft_strchr("0SNWE", str[i - 1]))
			return (0);
	return (1);
}

int		checkmapside(char **arr)
{
	int i;

	if (arr == NULL || arr[0] == NULL)
		return (0);
	if (checkfirststr(arr[0]) == 0)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (ft_strchr("0SWEN2", arr[i][0]) || checklast(arr[i]) == 0)
			return (0);
		i++;
	}
	if ((i - 1 >= 0) && checkfirststr(arr[i - 1]) == 0)
		return (0);
	if (checkinside(arr) == 0)
		return (0);
	return (1);
}
