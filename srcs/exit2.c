/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:57:17 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/07 16:57:18 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_spr(t_index *m)
{
	if (m->spr.zbuffer)
	{
		free(m->spr.zbuffer);
		m->spr.zbuffer = 0;
	}
	if (m->spr.sprites_x)
	{
		free(m->spr.sprites_x);
		m->spr.sprites_x = 0;
	}
	if (m->spr.sprites_y)
	{
		free(m->spr.sprites_y);
		m->spr.sprites_y = 0;
	}
}

void	free_tex(t_index *m)
{
	if (m->tex.color_n)
	{
		free(m->tex.color_n);
		m->tex.color_n = 0;
	}
	if (m->tex.color_s)
	{
		free(m->tex.color_s);
		m->tex.color_s = 0;
	}
	if (m->tex.color_e)
	{
		free(m->tex.color_e);
		m->tex.color_e = 0;
	}
	if (m->tex.color_w)
	{
		free(m->tex.color_w);
		m->tex.color_w = 0;
	}
}
