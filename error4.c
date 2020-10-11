/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:15:53 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:15:54 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		freexmp7(t_data *img)
{
	freexmp3(img);
	free(img->spritetext);
	return (12);
}

int		ft_errnocheck(int er, t_flags *flag, int fd)
{
	if (er == 13)
	{
		ft_putstr_fd("Error : Permission denied\n", 2);
		free(flag);
		close(fd);
		return (1);
	}
	if (er == 21)
	{
		ft_putstr_fd("ERROR : Realy?\n", 2);
		free(flag);
		close(fd);
		return (1);
	}
	if (er == 2)
	{
		ft_putstr_fd("Error : No such file or directory\n", 2);
		free(flag);
		close(fd);
		return (1);
	}
	return (0);
}
