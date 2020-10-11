/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:18:28 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:18:29 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putfloor1(t_data *img)
{
	int i;
	int j;

	i = 0;
	while (i < img->r1)
	{
		j = 0;
		while (++j < img->r2 / 2)
			my_mlx_pixel_put(img, i, j, img->floor);
		while (++j < img->r2)
			my_mlx_pixel_put(img, i, j, img->cellar);
		i++;
	}
}

void	ft_putscreen(t_data *img)
{
	if (!(img->mlx = mlx_init()))
		exit(printerror(cleanmap(img, 6)));
	img->coef = 1;
	inittexture(img);
	if (!(img->img = mlx_new_image(img->mlx, img->r1, img->r2)))
		exit(printerror(freexmp4(img)));
	if (!(img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,\
	&img->line_length, &img->endian)))
		exit(printerror(freexmp4(img)));
	ft_putcol(img);
	ft_putsprite(img);
	ft_putonelinepixel(img);
}
