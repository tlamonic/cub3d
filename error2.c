/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:15:34 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:15:35 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_malloc2(t_data *img, char **arr)
{
	error_setdata(img->flag, img);
	freemass(arr);
	return (0);
}

int		error_map(t_data *img, char **arr)
{
	error_setdata(img->flag, img);
	freemass(arr);
	return (5);
}

int		error_malloc3(t_data *img, char **arr, char **new, int i)
{
	error_setdata(img->flag, img);
	freemass(arr);
	freecharmass(new, i);
	return (0);
}

int		cleanmap(t_data *img, int error)
{
	freemass(img->map);
	error_setdata(img->flag, img);
	return (error);
}
