/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:18:54 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:18:55 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_collor(t_xpm *data, int x, int y)
{
	char	*dst;
	int		collor;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	collor = *(int*)dst;
	return (collor);
}

int		get_collordata(t_data *data, int x, int y)
{
	char	*dst;
	int		collor;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	collor = *(int*)dst;
	return (collor);
}

int		write_collor(t_data *data, int x, int y, int file)
{
	char	*dst;
	int		collor;
	int		rgb;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	collor = *(int*)dst;
	rgb = (collor & 0xFF0000) | (collor & 0x00FF00) | (collor & 0x0000FF);
	return (write(file, &collor, 3));
}
