
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char*s2;
	int i;

	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
