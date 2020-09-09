#include <fcntl.h>
#include <unistd.h>
#include "gnl/get_next_line.h"
#include "gnl/get_next_line.c"
#include "gnl/get_next_line_utils.c"
#include "libft/ft_atoi.c"
#include "libft/ft_strdup.c"
#include "libft/ft_isspace.c"
#include <stdio.h>
#include "cub3d.h"

void	getwall(char *str, t_map *mapa)
{
	char	c;

	c = *str;
	str += 2;
	if (ft_isspace(*str))
		str++;
	else
		return ;
	if (c == 'N')
		mapa->NO = ft_strdup(str);
	else if (c == 'S')
		mapa->SO = ft_strdup(str);
	else if (c == 'W')
		mapa->WE = ft_strdup(str);
	else if (c == 'E')
		mapa->EA = ft_strdup(str);
}

void	getres(char *str, t_map *mapa)
{
	str += 2;
	mapa->res[0] = ft_atoi(str);
	while (!ft_isspace(*str) && *str)
		str++;
	if (!str)
		return ;
	mapa->res[1] = ft_atoi(str);
}

void	getcolour(char *str, int *arr)
{
	str += 2;

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
	//if (*str == 'S' && *(str + 1) == ' ')
		//getsprite(str, mapa);
	if (*str == 'F' && *(str + 1) == ' ')
		getcolour(str, mapa->F);
	if (*str == 'C' && *(str + 1) == ' ')
		getcolour(str, mapa->C);
	if ((*str == 'N' || *str == 'S') && *(str + 1) == 'O')
		getwall(str, mapa);
	if (*str == 'W' && *(str + 1) == 'E')
		getwall(str, mapa);
	if (*str == 'E' && *(str + 1) == 'A')
		getwall(str, mapa);
}

int		parse(char *map, t_map *mapa)
{
	char	*str;
	int		fd;
	int		errcode;

	fd = open(map, O_RDONLY);
	while ((get_next_line(fd, &str)) > 0)
		getinfo(str, mapa);
	getinfo(str, mapa);
	free(str);
	return (errcode);
}
