/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdata_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:20:49 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:20:50 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*setno(char **str, t_flags *flag, t_data *img, char *line)
{
	char	*no;
	int		i;

	if (str[0][1] == 'O' && !flag->noflag && str[0][2] == '\0')
	{
		i = 0;
		while (line[i] != 'O')
			i++;
		i++;
		while (line[i] == ' ')
			i++;
		no = ft_strdup(line + i);
		no = cut_spases(no);
		flag->noflag = 1;
	}
	else
		exit(printerror(error_setdatar777(flag, img)));
	return (no);
}

char		*setwe(char **str, t_flags *flag, t_data *img, char *line)
{
	char	*we;
	int		i;

	if (str[0][1] == 'E' && !flag->weflag && str[0][2] == '\0')
	{
		i = 0;
		while (line[i] != 'E')
			i++;
		i++;
		while (line[i] == ' ')
			i++;
		we = ft_strdup(line + i);
		we = cut_spases(we);
		flag->weflag = 1;
	}
	else
		exit(printerror(error_setdatar777(flag, img)));
	return (we);
}

char		*setea(char **str, t_flags *flag, t_data *img, char *line)
{
	char	*ea;
	int		i;

	if (str[0][1] == 'A' && !flag->eaflag && str[0][2] == '\0')
	{
		i = 0;
		while (line[i] != 'A')
			i++;
		i++;
		while (line[i] == ' ')
			i++;
		ea = ft_strdup(line + i);
		ea = cut_spases(ea);
		flag->eaflag = 1;
	}
	else
		exit(printerror(error_setdatar777(flag, img)));
	return (ea);
}

char		*setso(char **str, t_flags *flag, t_data *img, char *line)
{
	char	*so;
	int		i;

	if (!flag->soflag && str[0][2] == '\0')
	{
		i = 0;
		while (line[i] != 'O')
			i++;
		i++;
		while (line[i] == ' ')
			i++;
		so = ft_strdup(line + i);
		so = cut_spases(so);
		flag->soflag = 1;
	}
	else
		exit(printerror(error_setdatar777(flag, img)));
	return (so);
}

char		*setsprite(char **str, t_flags *flag, t_data *img, char *line)
{
	char	*sprite;
	int		i;

	if (!flag->spriteflag && str[0][1] == '\0')
	{
		i = 0;
		while (line[i] != 'S')
			i++;
		i++;
		while (line[i] == ' ')
			i++;
		sprite = ft_strdup(line + i);
		sprite = cut_spases(sprite);
		flag->spriteflag = 1;
	}
	else
		exit(printerror(error_setdatar777(flag, img)));
	return (sprite);
}
