#include "cub3d.h"
#include "libft/ft_strdup.c"
#include <stdio.h>

void 	map(t_map *map, const char *str)
{
	//int 		i;
	static int 	j;

	//i = -1;
	printf("%d\n", j);
	*map->mapa = ft_strdup(str);
	j++;
}