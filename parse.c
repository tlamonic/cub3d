#include <fcntl.h>
#include <unistd.h>
#include "gnl/get_next_line.h"
#include "gnl/get_next_line.c"
#include "gnl/get_next_line_utils.c"
#include "libft/ft_atoi.c"
#include "libft/ft_strdup.c"
#include "libft/ft_isspace.c"
#include <stdio.h>
#include "errcheck.c"
#include "map.c"
#include "cub3d.h"

void	getwall(char *str, t_map *mapa)
{
	char	c;
	int 	i;

	i = 0;
	c = *str;
	str += 2;
	if (ft_isspace(*str))
		str++;
	else
		return ;
	while (c == 'N' && *str)
		mapa->NO[i++] = *str++;
	while (c == 'S' && *str)
		mapa->SO[i++] = *str++;
	while (c == 'W' && *str)
		mapa->WE[i++] = *str++;
	while (c == 'E' && *str)
		mapa->EA[i++] = *str++;
}

void	getres(char *str, t_map *mapa)
{
	if (mapa->res[0] || !str)
	{
		mapa->res[0] = 0;
		return ;
	}
	str += 2;
	mapa->res[0] = ft_atoi(str);
	while (!ft_isspace(*str) && *str)
		str++;
	mapa->res[1] = ft_atoi(str);
}

void	getcolour(char *str, int *arr)
{
	str += 2;

	if (arr[0])
	{
		arr[0] = 0;
		return ;
	}
	arr[0] = ft_atoi(str);
	while (*str != ',' && *str)
		str++;
	arr[1] = ft_atoi(++str);
	while (*str != ',' && *str)
		str++;
	arr[2] = ft_atoi(++str);
	if (arr[0] < 0 || arr[0] > 255)
		arr[0] = -1;
	if (arr[1] < 0 || arr[1] > 255)
		arr[0] = -1;
	if (arr[2] < 0 || arr[2] > 255)
		arr[0] = -1;
}

void	getinfo(char *str, t_map *mapa)
{
	if (*str == 'R' && *(str + 1) == ' ')
		getres(str, mapa);
	if (*str == 'F' && *(str + 1) == ' ')
		getcolour(str, mapa->F);
	if ((*str == 'N' || *str == 'S') && *(str + 1) == 'O')
		getwall(str, mapa);
	if (*str == 'W' && *(str + 1) == 'E')
		getwall(str, mapa);
	if (*str == 'E' && *(str + 1) == 'A')
		getwall(str, mapa);
	if (*str == 'C' && *(str + 1) == ' ')
		getcolour(str, mapa->C);
	else
		map(mapa, str);
}

int		parse(char *map, t_map *mapa)
{
	char	*str;
	int		fd;
	int 	i;

	i = 0;
	fd = open(map, O_RDONLY);
	while ((get_next_line(fd, &str)) > 0)
	{
		if (*str == 'S' && *(str + 1) == ' ')
		{
			str += 2;
			while (*str)
				mapa->S[i++] = *str++;
		}
		else
			getinfo(str, mapa);
	}
	free(str);
	return (errcheck(mapa));
}
