#include "../cub3d.h"

int		write_error_res(void)
{
	write(1, "Error\n", 6);
	write(1, "Wrong arguments\n", 16);
	exit(0);
	return (-1);
}

int		calcul_digit(t_index *m, int i)
{
	int	digit;

	digit = 0;
	while (m->el.elem[m->el.resolution_line][i] == ' ')
		i++;
	while (m->el.elem[m->el.resolution_line][i] >= '0' &&
		m->el.elem[m->el.resolution_line][i] <= '9')
	{
		digit = (digit * 10) + m->el.elem[m->el.resolution_line][i] - '0';
		i++;
	}
	m->el.res_x = digit;
	return (i);
}

int		get_resolution(t_index *m)
{
	int	i;
	int	digit;

	digit = 0;
	i = 1;
	i = calcul_digit(m, i);
	while (m->el.elem[m->el.resolution_line][i] == ' ')
		i++;
	if (m->el.elem[m->el.resolution_line][i] == '\0' ||
			!ft_isdigit(m->el.elem[m->el.resolution_line][i]))
		write_error_res();
	while (m->el.elem[m->el.resolution_line][i] >= '0' &&
			m->el.elem[m->el.resolution_line][i] <= '9')
	{
		digit = (digit * 10) + m->el.elem[m->el.resolution_line][i] - '0';
		i++;
	}
	m->el.res_y = digit;
	while (m->el.elem[m->el.resolution_line][i] != '\0')
	{
		if (m->el.elem[m->el.resolution_line][i] != ' ')
			write_error_res();
		i++;
	}
	return (1);
}
