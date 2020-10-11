/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:16:15 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:16:17 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		wallc(t_data *img)
{
	double c;
	double x;
	double y;

	c = 0;
	dostep1(&c, img->x, img->y, img->mainangle);
	x = img->x + c * cos(img->mainangle);
	y = img->y + c * sin(img->mainangle);
	if ((img->map[(int)x][(int)y] == '1' || \
	img->map[(int)x][(int)y] == '\0') && \
	c <= 0.25)
		return (1);
	return (0);
}

t_data	*ft_w(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.2 * cos(img->mainangle);
	y = img->y + 0.2 * sin(img->mainangle);
	if (img->map[(int)x][(int)y] != '1' && \
	img->map[(int)x][(int)y] != '\0'\
	&& wallc(img) == 0)
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}

t_data	*ft_s(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.13 * cos(img->mainangle - M_PI);
	y = img->y + 0.13 * sin(img->mainangle - M_PI);
	if (img->map[(int)x][(int)y] != '1' && \
	img->map[(int)x][(int)y] != '\0')
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}

t_data	*ft_d(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.13 * cos(img->mainangle - M_PI_2);
	y = img->y + 0.13 * sin(img->mainangle - M_PI_2);
	if (img->map[(int)x][(int)y] != '1' && \
	img->map[(int)x][(int)y] != '\0')
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}

t_data	*ft_a(t_data *img)
{
	double x;
	double y;

	x = img->x + 0.13 * cos(img->mainangle + M_PI_2);
	y = img->y + 0.13 * sin(img->mainangle + M_PI_2);
	if (img->map[(int)x][(int)y] != '1' && \
	img->map[(int)x][(int)y] != '\0')
	{
		img->x = x;
		img->y = y;
	}
	return (img);
}
