
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	ptr = (char *)s + len - 1;
	if (c == '\0')
		return (ptr + 1);
	while (len > 0)
	{
		if (*ptr == c)
			return (ptr);
		ptr--;
		len--;
	}
	if (c == '\0')
	{
		ptr++;
		return (ptr);
	}
	return (NULL);
}
