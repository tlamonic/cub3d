#include "cub3d.h"
#include <stdio.h>

int 	errcheck(t_map *mapa)
{
	int		err;

	err = 0;
	if (!*mapa->EA || !*mapa->WE || !*mapa->SO
	|| !*mapa->NO)
		err = printf("Wrong path to the textures\n");
	if (mapa->res[0] == 0)
		err = printf("Wrong resolution\n");
	if (mapa->F[0] == 0 || mapa->C[0] == 0)
		err = printf("Wrong colour\n");
	return (err);
}