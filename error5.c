/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:16:01 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:16:04 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_setdatar777(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (777);
}

int		error_setdatar1(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (11);
}

int		error_setdatar99(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (99);
}

int		error_setdata1(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (10);
}

int		error_setdata0(t_flags *flag, t_data *img)
{
	error_setdata(flag, img);
	return (0);
}
