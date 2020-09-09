#include <stdio.h>
#include "libft/ft_strlen.c"
#include "libft/ft_strncmp.c"
#include "parse.c"
#include "cub3d.h"

int		res(char *str)
{
	const char	*res = ".cub";
	int			i;

	if (ft_strlen(str) <= 4)
		return (0);
	i = ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], (char*)res, ft_strlen(res)))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		errcode;

	t_map	mapa;
	if (argc < 2 || argc > 3)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	if (!res(argv[1]))
	{
		printf("Invalid map's name\n");
		return (0);
	}
	parse(argv[1], &mapa);
	return (0);
}
