
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;

	if (*lst == NULL || del == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		*lst = ptr;
		ft_lstdelone(*lst, del);
		ptr = ptr->next;
	}
	*lst = NULL;
}
