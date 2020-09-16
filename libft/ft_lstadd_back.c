/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:22:38 by student           #+#    #+#             */
/*   Updated: 2020/05/11 17:44:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (*lst && lst)
	{
		list = *lst;
		while (list->next)
			list = list->next;
		list->next = new;
		list = list->next;
		list->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}
