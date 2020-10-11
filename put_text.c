/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:20:09 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:20:10 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_putonelinepixel(t_data *img)
{
	int i;

	i = 0;
	while (i < img->r1)
	{
		if (img->r2 > 2)
			my_mlx_pixel_put(img, i, img->r2 - 1, \
					get_collordata(img, i, img->r2 - 2));
		my_mlx_pixel_put(img, i, 0, get_collordata(img, i, 1));
		i++;
	}
}

char		*cut_spases(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i < 0)
		return (NULL);
	i--;
	while (str[i] == ' ')
		i--;
	str[i + 1] = '\0';
	return (str);
}
