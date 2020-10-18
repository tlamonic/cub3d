/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:01:42 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/18 16:01:29 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		return_error(t_index *m)
{
	write(1, "Error\n", 6);
	write(1, "Multiple initial positions\n", 27);
	return (exit_all(m));
}

int		write_error_one(t_index *m)
{
	write(1, "Error\n", 6);
	write(1, "Error in parsing\n", 17);
	return (exit_all(m));
}

char	*parse_map(int fd, t_index *m)
{
	char	*line;
	char	*str;

	line = "";
	str = NULL;
	while (line[0] == '\0')
	{
		get_next_line(fd, &line);
		if (line[0] == '\0')
			free(line);
	}
	str = ft_strjoin(str, line);
	str = ft_strjoin(str, "\n");
	free(line);
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			write_error_one(m);
		str = ft_strjoin(str, line);
		str = ft_strjoin(str, "\n");
		free(line);
		line = NULL;
	}
	str = ft_strjoin(str, line);
	str = ft_strjoin(str, "\0");
	free(line);
	line = NULL;
	return (str);
}

char	*parse_data(int fd)
{
	char	*line;
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) && i < 7)
	{
		if (line[0] == '\0')
		{
			free(line);
			get_next_line(fd, &line);
		}
		if (!ft_isdigit(line[0]))
		{
			str = ft_strjoin(str, line);
			str = ft_strjoin(str, "\n");
			free(line);
			line = NULL;
			i++;
		}
	}
	while (line[0] == '\0')
		get_next_line(fd, &line);
	str = ft_strjoin(str, line);
	str = ft_strjoin(str, "\0");
	free(line);
	line = NULL;
	return (str);
}

int		parse_cub(t_index *m, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (!(m->parse.data = parse_data(fd)))
		return (-1);
	if (!(m->parse.map_string = parse_map(fd, m)))
		return (-1);
	close(fd);
	if (create_map(m) < 0)
		return (-1);
	if (create_good_size_map(m) < 0)
		return (-1);
	if (get_sprites(m) < 0)
		return (-1);
	if (get_elements(m) < 0)
		return (-1);
	if (check_elements_errors(m) < 0)
		return (-1);
	if (check_map_errors(m) < 0)
		return (-1);
	return (1);
}
