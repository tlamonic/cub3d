/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somefree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:20:57 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:20:58 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freecharmass(char **str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	freemass(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_freeall(t_data *img)
{
	free(img->notext);
	free(img->sotext);
	free(img->wetext);
	free(img->eatext);
	free(img->spritetext);
	freemass(img->map);
	free(img->no);
	free(img->so);
	free(img->we);
	free(img->ea);
	free(img->sprite);
}
