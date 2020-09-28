
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[j] != ('\0') && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}