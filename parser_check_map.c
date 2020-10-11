/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:19:38 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:19:39 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkline(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("02NWES", line[i]))
			return (1);
		i++;
	}
	return (0);
}

int		checkarr(char **map)
{
	int i;
	int len;

	i = 0;
	len = ft_maxlenarr(map);
	while (map[i])
	{
		if (ft_strchr("02NWES", map[i][0]))
			return (1);
		if (ft_strchr("02NWES", map[i][len]))
			return (1);
		i++;
	}
	return (0);
}

int		checktwohero(char **map, t_data *img)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (checknwes(map[i][j]) == 1)
			{
				flag++;
				img->mainangle = ft_angle(map[i][j]);
				map[i][j] = '0';
				img->x = i + 0.5;
				img->y = j + 0.5;
			}
		}
	}
	return (flag);
}

int		ft_checkmap(char **map, t_data *img)
{
	int i;

	i = checktwohero(map, img);
	if (i > 1)
		exit(printerror(cleanmap(img, 3)));
	else if (i == 0)
		exit(printerror(cleanmap(img, 2)));
	if (checkunknownsymbol(map) != 0)
		exit(printerror(cleanmap(img, 4)));
	if (checkline(map[0]) == 1 || \
	checkline(map[ft_arrlen(map) - 1]) == 1)
		exit(printerror(cleanmap(img, 5)));
	if (checkarr(map) == 1)
		exit(printerror(cleanmap(img, 5)));
	if (checkmapside(map) == 0)
		exit(printerror(cleanmap(img, 5)));
	return (1);
}
