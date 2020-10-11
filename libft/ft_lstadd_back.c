/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:22:55 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:22:56 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *a;
	t_list *b;

	a = new;
	b = *lst;
	if (b)
	{
		while (b->next)
			b = b->next;
		b->next = a;
	}
	else
		*lst = a;
}
