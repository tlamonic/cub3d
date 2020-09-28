
#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (new != NULL)
		*alst = new;
}
