/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:59:16 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/08 15:22:31 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map_characters(t_index *m)
{
	int i;

	i = 0;
	while (m->parse.map_string[i] != '\0')
	{
		if (m->parse.map_string[i] != '1' &&
			m->parse.map_string[i] != '2' &&
			m->parse.map_string[i] != '0' &&
			m->parse.map_string[i] != 'N' &&
			m->parse.map_string[i] != 'S' &&
			m->parse.map_string[i] != 'E' &&
			m->parse.map_string[i] != 'W' &&
			m->parse.map_string[i] != ' ' &&
			m->parse.map_string[i] != '\n')
		{
			write(1, "Error\n", 6);
			write(1, "Map contains wrong things\n", 26);
			return (exit_all(m));
		}
		i++;
	}
	return (1);
}

int		check_around(int i, int j, t_index *m)
{
	if (m->parse.map[i][j - 1] == ' ')
		return (-1);
	if (m->parse.map[i][j + 1] == ' ')
		return (-1);
	if (m->parse.map[i - 1][j] == ' ')
		return (-1);
	if (m->parse.map[i + 1][j] == ' ')
		return (-1);
	return (1);
}

int		check_spaces_algo(t_index *m)
{
	int i;
	int j;

	i = 1;
	while (i < (m->parse.line_nbr - 1))
	{
		j = 1;
		while (m->parse.map[i][j] != '\0')
		{
			if ((m->parse.map[i][j] == '0' && (check_around(i, j, m) < 0)))
				return (return_error_exit(m));
			if ((m->parse.map[i][j] == '2' && (check_around(i, j, m) < 0)))
				return (return_error_exit(m));
			j++;
		}
		i++;
	}
	return (1);
}

int		check_map_errors(t_index *m)
{
	if (check_spaces_algo(m) < 0)
		return (-1);
	if (check_dir_letter(m) < 0)
	{
		write(1, "Error\nThere's no player on the map\n", 35);
		return (-1);
	}
	if (check_map_characters(m) < 0)
		return (-1);
	return (1);
}
