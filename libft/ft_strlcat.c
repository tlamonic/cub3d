
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0')
		j++;
	k = i + j;
	if (i == size)
		return (k);
	j = 0;
	while (src[j] != '\0' && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (k);
}
