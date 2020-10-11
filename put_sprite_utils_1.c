/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:00:44 by fbarbera          #+#    #+#             */
/*   Updated: 2020/10/02 06:00:24 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_elem(t_data *img, t_sprite *spr, double s)
{
	int i;
	int x;
	int y;

	x = img->mapx;
	y = img->mapy;
	i = 0;
	if (s < 0.8)
		return (1);
	while (i < img->num)
	{
		if (spr[i].x == (int)x + 0.5 && spr[i].y == (int)y + 0.5)
			return (1);
		i++;
	}
	return (0);
}

int		**ft_malloc_arrayint(int i, int j)
{
	int **arr;
	int k;

	if (!(arr = malloc(sizeof(int*) * i)))
		exit(0);
	k = 0;
	while (k < i)
	{
		if (!(arr[k] = malloc(sizeof(int) * j)))
			exit(0);
		k++;
	}
	return (arr);
}

void	freeintmass(int **arr, int i)
{
	int k;

	k = 0;
	while (k < i)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

void	null_mas(t_sprite *spr, int i)
{
	int k;

	k = 0;
	while (k < i)
	{
		spr[k].x = 0;
		spr[k].y = 0;
		spr[k].average = 0;
		k++;
	}
}

void	bubblesort(t_sprite *spr, int size)
{
	int			i;
	int			flag;
	t_sprite	tmp;

	flag = 1;
	while (flag > 0)
	{
		flag = 0;
		i = -1;
		while (++i < size - 1)
		{
			if (spr[i].average < spr[i + 1].average)
			{
				tmp = spr[i + 1];
				spr[i + 1] = spr[i];
				spr[i] = tmp;
				flag++;
			}
		}
	}
}
