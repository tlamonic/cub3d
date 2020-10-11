/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:16:23 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:16:25 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	presetsprite(int i, t_data *img)
{
	int c;

	bubblesort(img->spr, i);
	c = 0;
	while (c < i)
	{
		if (img->spr[(int)c].average > 0.7)
			putsprite(img, (int)c);
		c++;
	}
}

void	somefun(t_data *img, int *i)
{
	if (img->map[(int)img->mapx][(int)img->mapy] == '2' && \
	check_elem(img, img->spr, \
	(sqrt(pow((img->x - (int)img->mapx - 0.5), 2) \
	+ pow((img->y - (int)img->mapy - 0.5), 2)))) == 0)
	{
		img->spr[*i].x = (int)img->mapx + 0.5;
		img->spr[*i].y = (int)img->mapy + 0.5;
		img->spr[*i].average = (sqrt(pow((img->x - img->spr[*i].x), 2) \
		+ pow((img->y - img->spr[*i].y), 2)));
		img->spr[*i].angle = correctangle1(atan2((img->spr[*i].y - img->y),\
		(img->spr[*i].x - img->x)), \
		img->mainangle);
		*i = *i + 1;
	}
}

void	ft_putsprite(t_data *img)
{
	double	angle1;
	int		i;
	double	c;

	angle1 = img->mainangle - M_PI / 6;
	i = 0;
	null_mas(img->spr, img->num);
	while (angle1 < img->mainangle + M_PI / 6)
	{
		c = 0.001;
		while (wallfounder(img, c, angle1) != 1)
		{
			somefun(img, &i);
			dostep1(&c, img->mapx, img->mapy, angle1);
		}
		angle1 += 5 * M_PI / (img->r1 * 3);
	}
	presetsprite(i, img);
	free(img->deep);
}
