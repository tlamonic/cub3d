/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:59:21 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/07 16:59:22 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		new_strlen(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int		check_dir_letter(t_index *m)
{
	if (m->parse.dir == 'N' || m->parse.dir == 'S' ||
		m->parse.dir == 'E' || m->parse.dir == 'W')
		return (0);
	return (-1);
}

int		return_error_exit(t_index *m)
{
	write(1, "Error\n", 6);
	write(1, "The map is not surrounded by 1\n", 31);
	exit_all(m);
	return (-1);
}

int		check_borders_columns(t_index *m)
{
	int i;
	int j;

	i = 0;
	while (m->parse.map[i] != NULL)
	{
		j = 0;
		while (m->parse.map[i][j] != '\0')
			j++;
		if (m->parse.map[i][j - 1] != '1')
			return_error_exit(m);
		i++;
	}
	i = 0;
	while (m->parse.map[i] != NULL)
	{
		if (m->parse.map[i][0] != '1' && m->parse.map[i][0] != ' ')
			return_error_exit(m);
		i++;
	}
	return (1);
}

int		check_borders_lines(t_index *m)
{
	int j;

	j = 0;
	while (m->parse.map[0][j] != '\0')
	{
		if (m->parse.map[0][j] != '1' && m->parse.map[0][j] != ' ')
			return_error_exit(m);
		j++;
	}
	j = 0;
	while (m->parse.map[m->parse.line_nbr - 1][j] != '\0')
	{
		if (m->parse.map[m->parse.line_nbr - 1][j] != '1' &&
			m->parse.map[m->parse.line_nbr - 1][j] != ' ')
			return_error_exit(m);
		j++;
	}
	return (1);
}
