
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (*alst != NULL)
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if (new != NULL)
		*alst = new;
}
