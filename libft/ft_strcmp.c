
#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (i < (ft_strlen(s1) + 1))
		return (-1);
	return (1);
}
