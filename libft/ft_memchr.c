
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c2;
	int				i;

	ptr = (unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (ptr[i] == c2)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
