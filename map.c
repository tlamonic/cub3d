#include "cub3d.h"
#include "libft/ft_strdup.c"
#include "libft/ft_strchr.c"
#include <stdio.h>

//str - новая строка мапы

void	create_arr(t_map *map, const char *str)
{
	map->mapa = malloc(sizeof(char*) * 2);
	map->mapa[0] = ft_strdup(str);
	map->mapa[1] = ft_strdup("\0");
}

void 	map(t_map *map, const char *str)
{
	int 	j;
	int		i;
	char	**arr;

	if (!ft_strchr(str, '1'))
		return ;
	if (!map->mapa)
	{
		create_arr(map, str);
		return ;
	}
	i = 0;
	j = -1;
	while (map->mapa[i][0])
		i++;
	arr = malloc(sizeof(char*) * (i + 1));
	while (map->mapa[++j][0])
		arr[j] = ft_strdup(map->mapa[j]);
	arr[j] = ft_strdup("\0");
	i = -1;
	while (++i < j)
		free(map->mapa[i]);
	free(map->mapa);
	map->mapa = arr;
}
