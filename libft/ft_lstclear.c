/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:22:52 by student           #+#    #+#             */
/*   Updated: 2020/05/11 01:15:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		list = *lst;
		*lst = (*lst)->next;
		del(list->content);
		free(list);
	}
	*lst = NULL;
}
