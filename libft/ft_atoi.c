/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:04:56 by student           #+#    #+#             */
/*   Updated: 2020/05/27 16:03:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int flag;

	if (!str)
		return (0);
	i = 0;
	flag = 1;
	while (*str == 10 || *str == 9 || *str == 32 || *str == 11 || *str == 12
			|| *str == 13)
		str++;
	if (*str == 45)
		flag *= -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		i = i * 10 + *str - 48;
		str++;
	}
	return (i * flag);
}
