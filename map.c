#include "cub3d.h"
#include "libft/ft_strchr.c"

# define play "NSOW"

int 	map(t_map *mapa, char *str)
{
	int		player;

	player = 0;
	while (*str)
	{
		if (ft_strchr(play, *str))
		{
			if (player)
				return (0);
			player = 1;
		}
		
	}
}