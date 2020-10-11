/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfloorcollor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:16:35 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:16:36 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parsercolor(char *str, int *rgb)
{
	int i;

	rgb[0] = ft_atoi(str);
	i = ft_intlenn(rgb[0]);
	if (str[i] == ',')
		i++;
	else
		return (0);
	rgb[1] = ft_atoi(str + i);
	i += ft_intlenn(rgb[1]);
	if (str[i] == ',')
		i++;
	else
		return (0);
	rgb[2] = ft_atoi(str + i);
	i += ft_intlenn(rgb[2]);
	if (str[i] != '\0')
		return (0);
	free(str);
	return (1);
}

int		ft_checkcolor(int *rgb)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] > 255 || rgb[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

int		*ft_setrgb(char **arr)
{
	int		*rgb;
	char	*str;

	if (!(str = ft_dostr(arr + 1)))
	{
		freemass(arr);
		return (NULL);
	}
	if (ft_checksymbols(str) == 1)
		return (NULL);
	if (!(rgb = malloc(sizeof(int) * 3)))
		return (NULL);
	if (!ft_parsercolor(str, rgb))
		return (NULL);
	if (ft_checkcolor(rgb) == 0)
		return (NULL);
	return (rgb);
}

int		ft_setfloorcollor(char **str, t_data *img)
{
	int *rgb;
	int collor;

	if ((rgb = ft_setrgb(str)) == NULL)
		exit(printerror(error_setdata1(img->flag, img)));
	collor = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	free(rgb);
	return (collor);
}
