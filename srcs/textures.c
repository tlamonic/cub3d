#include "../cub3d.h"

void	calculate_colors(t_index *m)
{
	if (m->big.side == 1 && (m->big.mapy > m->big.posy))
		m->tex.color = (int *)m->tex.color_s;
	else if (m->big.side == 1 && (m->big.mapy < m->big.posy))
		m->tex.color = (int *)m->tex.color_n;
	else if (m->big.side == 0 && (m->big.mapx > m->big.posx))
		m->tex.color = (int *)m->tex.color_e;
	else
		m->tex.color = (int *)m->tex.color_w;
	m->spr.color = (int *)m->spr.spr_tex;
}

void	calculate_textures(t_index *m)
{
	float	wallx;

	if (m->big.side == 0)
		wallx = m->big.posy + m->big.perpwalldist * m->big.raydiry;
	else
		wallx = m->big.posx + m->big.perpwalldist * m->big.raydirx;
	wallx -= floor((wallx));
	m->tex.texx = (int)(wallx * m->tex.texheight);
	if (m->big.side == 0 && m->big.raydirx > 0)
		m->tex.texx = m->tex.texwidth - m->tex.texx - 1;
	if (m->big.side == 1 && m->big.raydiry < 0)
		m->tex.texx = m->tex.texwidth - m->tex.texx - 1;
	m->tex.step = 1.0 * m->tex.texheight / m->big.lineheight;
	m->tex.texpos = (m->big.drawstart - m->el.res_y / 2 + m->big.lineheight / 2)
		* m->tex.step;
}

int		create_images2(t_index *m)
{
	if (!(m->tex.color_e = mlx_xpm_file_to_image(m->win.mlx_ptr, m->el.e_path,
		&m->tex.texwidth, &m->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "e wrong path texture", 20);
		exit_all(m);
		return (exit_all(m));
	}
	if (!(m->spr.spr_tex = mlx_xpm_file_to_image(m->win.mlx_ptr, m->el.spr_path,
		&m->spr.sprwidth, &m->spr.sprheight)))
	{
		write(1, "Error\n", 6);
		write(1, "texture of the sprite is wrong", 30);
		return (exit_all(m));
	}
	return (1);
}

int		create_images1(t_index *m)
{
	if (!(m->tex.color_n = mlx_xpm_file_to_image(m->win.mlx_ptr, m->el.n_path,
		&m->tex.texwidth, &m->tex.texwidth)))
	{
		write(1, "Error\n", 6);
		write(1, "n wrong path texture\n", 20);
		return (exit_all(m));
	}
	if (!(m->tex.color_s = mlx_xpm_file_to_image(m->win.mlx_ptr, m->el.s_path,
		&m->tex.texwidth, &m->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "s wrong path texture", 20);
		return (exit_all(m));
	}
	if (!(m->tex.color_w = mlx_xpm_file_to_image(m->win.mlx_ptr, m->el.w_path,
		&m->tex.texwidth, &m->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "w wrong path texture", 20);
		return (exit_all(m));
	}
	return (1);
}

int		generate_textures(t_index *m)
{
	if (create_images1(m) < 0)
		return (exit_all(m));
	if (create_images2(m) < 0)
		return (exit_all(m));
	m->tex.color_n = mlx_get_data_addr(m->tex.color_n,
		&m->img.bits_per_pixel, &m->img.line_length, &m->img.endian);
	m->tex.color_s = mlx_get_data_addr(m->tex.color_s,
		&m->img.bits_per_pixel, &m->img.line_length, &m->img.endian);
	m->tex.color_w = mlx_get_data_addr(m->tex.color_w,
		&m->img.bits_per_pixel, &m->img.line_length, &m->img.endian);
	m->tex.color_e = mlx_get_data_addr(m->tex.color_e,
		&m->img.bits_per_pixel, &m->img.line_length, &m->img.endian);
	m->spr.spr_tex = mlx_get_data_addr(m->spr.spr_tex,
		&m->img.bits_per_pixel, &m->img.line_length, &m->img.endian);
	return (0);
}
