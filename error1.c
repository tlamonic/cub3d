/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:15:18 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:25:31 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		printerror1(int error)
{
	if (error == 12)
		ft_putstr_fd("Error\nWrong texture name\n", 2);
	if (error == 404)
		ft_putstr_fd("Error\nScreen file\n", 2);
	if (error == 403)
		ft_putstr_fd("Error\nBitmap write\n", 2);
	if (error == 777)
		ft_putstr_fd("Error\nUnknown symbol or data isn't full\n", 2);
	if (error == 999)
		ft_putstr_fd("Error\nWrong arguments\n", 2);
	if (error == 99)
		ft_putstr_fd("Error\nWrong file data\n", 2);
	return (0);
}

int		printerror(int error)
{
	if (error == 0)
		ft_putstr_fd("Error\nMalloc\n", 2);
	if (error == 1)
		ft_putstr_fd("Error\nSymbol in the file\n", 2);
	if (error == 3)
		ft_putstr_fd("Error\nMultiple player's declaration\n", 2);
	if (error == 2)
		ft_putstr_fd("Error\nThere's no player\n", 2);
	if (error == 4)
		ft_putstr_fd("Error\nUnknown symbol\n", 2);
	if (error == 5)
		ft_putstr_fd("Error\nWrong map\n", 2);
	if (error == 6)
		ft_putstr_fd("Error\nInit mlx\n", 2);
	if (error == 10)
		ft_putstr_fd("Error\nWrong collor\n", 2);
	if (error == 11)
		ft_putstr_fd("Error\nWrong resolution\n", 2);
	if (printerror1(error))
		return (0);
	return (0);
}

int		error_setdata(t_flags *flag, t_data *img)
{
	if (flag->noflag == 1)
		free(img->no);
	if (flag->weflag == 1)
		free(img->we);
	if (flag->eaflag == 1)
		free(img->ea);
	if (flag->soflag == 1)
		free(img->so);
	if (flag->spriteflag == 1)
		free(img->sprite);
	free(flag);
	return (1);
}

int		error_inside(t_flags *flag, t_data *img, char **arr, int i)
{
	int k;

	k = -1;
	error_setdata(flag, img);
	while (++k < i)
		free(arr[k]);
	free(arr);
	return (0);
}
