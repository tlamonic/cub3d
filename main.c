#include <stdio.h>
#include "libft/ft_strlen.c"
#include "libft/ft_strncmp.c"
#include "libft/ft_bzero.c"
#include "parse.c"
#include "cub3d.h"

int		res(char *str)
{
	const char	*res = ".cub";
	int			i;

	if (ft_strlen(str) <= 4)
		return (0);
	i = (int)ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], (char*)res, ft_strlen(res)))
		return (0);
	return (1);
}

void	map_init(t_map *mapa)
{
	ft_bzero(mapa->EA, 50);
	ft_bzero(mapa->WE, 50);
	ft_bzero(mapa->NO, 50);
	ft_bzero(mapa->SO, 50);
	ft_bzero(mapa->S, 50);
	ft_bzero(mapa->res, 2);
	ft_bzero(mapa->F, 3);
	ft_bzero(mapa->C, 3);
}

int		main(int argc, char **argv)
{
	t_map	mapa;

	map_init(&mapa);
	if (argc < 2 || (argc >= 3 && ft_strncmp(argv[2], "--save", 6)))
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	if (!res(argv[1]))
	{
		printf("Invalid map's name\n");
		return (0);
	}
	if (parse(argv[1], &mapa))
		return (0);
	return (0);
}
