/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_ceilling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:59:28 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/07 16:59:29 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		write_error_ceilling(t_index *m, int i)
{
	if (m->el.elem[m->el.c_l][i] == '\0' ||
		m->el.elem[m->el.c_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong ceilling arguments\n", 25);
		exit_all(m);
	}
	return (-1);
}

int		write_error_end_ceilling(t_index *m, int i)
{
	if (m->el.elem[m->el.c_l][i] != ' ')
	{
		write(1, "Error\n", 6);
		write(1, "Wrong ceilling arguments\n", 25);
		exit_all(m);
	}
	return (-1);
}

int		get_ceilling_color(t_index *m)
{
	int i;

	i = 0;
	while (m->el.elem[m->el.c_l][++i] == ' ')
		i++;
	while (m->el.elem[m->el.c_l][i] >= '0' && m->el.elem[m->el.c_l][i] <= '9')
		m->el.c_r = (m->el.c_r * 10) + m->el.elem[m->el.c_l][i++] - '0';
	i = i - 1;
	while (m->el.elem[m->el.c_l][++i] != ',')
		write_error_ceilling(m, i);
	while (!ft_isdigit(m->el.elem[m->el.c_l][++i]))
		write_error_ceilling(m, i);
	while (m->el.elem[m->el.c_l][i] >= '0' && m->el.elem[m->el.c_l][i] <= '9')
		m->el.c_g = (m->el.c_g * 10) + m->el.elem[m->el.c_l][i++] - '0';
	i = i - 1;
	while (m->el.elem[m->el.c_l][++i] != ',')
		write_error_ceilling(m, i);
	while (!ft_isdigit(m->el.elem[m->el.c_l][++i]))
		write_error_ceilling(m, i);
	while (m->el.elem[m->el.c_l][i] >= '0' && m->el.elem[m->el.c_l][i] <= '9')
		m->el.c_b = (m->el.c_b * 10) + m->el.elem[m->el.c_l][i++] - '0';
	i = i - 1;
	while (m->el.elem[m->el.c_l][++i] != '\0')
		write_error_end_ceilling(m, i);
	return (0);
}
