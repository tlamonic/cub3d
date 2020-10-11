/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:15:42 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:15:43 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		freexmp1(t_data *img)
{
	cleanmap(img, 0);
	free(img->notext);
	return (0);
}

int		freexmp2(t_data *img)
{
	freexmp1(img);
	free(img->sotext);
	return (0);
}

int		freexmp3(t_data *img)
{
	freexmp2(img);
	free(img->eatext);
	return (0);
}

int		freexmp4(t_data *img)
{
	freexmp3(img);
	free(img->spritetext);
	return (0);
}

int		freexmp5(t_data *img)
{
	freexmp4(img);
	free(img->deep);
	return (0);
}
