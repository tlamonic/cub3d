/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:07:25 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/08 15:18:59 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_colors(t_index *m)
{
	if (m->el.c_r > 255 || m->el.c_b > 255 || m->el.c_g > 255)
	{
		write(1, "Error\nWrong ceilling arguments\n", 31);
		return (-1);
	}
	if (m->el.f_r > 255 || m->el.f_b > 255 || m->el.f_g > 255)
	{
		write(1, "Error\nWrong floor arguments", 28);
		return (-1);
	}
	return (0);
}
