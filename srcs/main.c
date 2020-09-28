
#include "../cub3d.h"

void	verline(int i, t_index *m)
{
	int j;
	int k;
	int y;

	j = 0;
	y = m->big.drawstart;
	while (j < y)
	{
		m->img.addr[j * m->el.res_x + i] = m->el.c_color_hex;
		j++;
	}
	while (y < m->big.drawend)
	{
		m->tex.texy = (int)m->tex.texpos & (m->tex.texheight - 1);
		m->tex.texpos += m->tex.step;
		m->img.addr[y * m->el.res_x + i] =
			m->tex.color[m->tex.texy * m->tex.texheight + m->tex.texx];
		y++;
	}
	k = y;
	while (k < m->el.res_y)
	{
		m->img.addr[k * m->el.res_x + i] = m->el.f_color_hex;
		k++;
	}
}

int		transform_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	create_algo(t_index *m)
{
	int		i;
	int		hit;

	i = 0;
	hit = 0;
	while (i < m->el.res_x)
	{
		hit = 0;
		calculate_ray_and_deltadist(i, m);
		calculate_step_and_sidedist(m);
		perform_dda(hit, m);
		calculate_dist(m);
		calculate_height_wall(m);
		calculate_textures(m);
		calculate_colors(m);
		verline(i, m);
		m->spr.zbuffer[i] = m->big.perpwalldist;
		i++;
	}
	sprites_raycasting(m);
	mlx_put_image_to_window(m->win.mlx_ptr, m->win.mlx_win, m->img.img, 0, 0);
}

int		launch_program(t_index *m, char *av)
{
	create_init(m);
	if (parse_cub(m, av) < 0)
		return (-1);
	if (!(m->win.mlx_ptr = mlx_init()))
		return (-1);
	m->win.mlx_win = mlx_new_window(m->win.mlx_ptr,
		m->el.res_x, m->el.res_y, WINDOW_TITLE);
	create_data(m);
	generate_textures(m);
	m->img.img = mlx_new_image(m->win.mlx_ptr, m->el.res_x, m->el.res_y);
	m->img.addr = (int *)mlx_get_data_addr(m->img.img, &m->img.bits_per_pixel,
		&m->img.line_length, &m->img.endian);
	create_algo(m);
	return (1);
}

int		main(int ac, char **av)
{
	t_index		m;

	if (ft_errors(ac, av) < 0)
		return (-1);
	else if (ac == 2)
	{
		if ((launch_program(&m, av[1])) < 0)
			return (exit_all(&m));
		mlx_hook(m.win.mlx_win, 2, 1L << 1, ft_key, &m);
		mlx_hook(m.win.mlx_win, 17, 0, exit_all, &m);
		mlx_loop(m.win.mlx_ptr);
	}
	else if (ac == 3 && !ft_strncmp(av[2], "--save", 5))
	{
		if ((launch_program(&m, av[1])) < 0)
			return (exit_all(&m));
		if (screen_shot(&m) < 0)
			return (exit_all(&m));
	}
	else
		exit_all(&m);
	return (0);
}
