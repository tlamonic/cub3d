
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	d = dest;
	s = src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == NULL)
		return (NULL);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
