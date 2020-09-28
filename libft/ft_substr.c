
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	if (len <= 0 || s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(dest = (char *)malloc(sizeof(char))))
			return (0);
		dest[0] = '\0';
		return (dest);
	}
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (len > 0)
	{
		dest[i] = s[i + start];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
