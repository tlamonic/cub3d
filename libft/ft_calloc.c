
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (size * count))))
		return (0);
	i = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}
