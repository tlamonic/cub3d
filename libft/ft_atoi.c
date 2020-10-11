/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:21:28 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:21:29 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoibig(const char *nptr, int *minus)
{
	int		len;

	len = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		len++;
		nptr++;
		if (len > 19 && *minus == 1)
			return (1);
		if (len > 19 && *minus == -1)
		{
			*minus = 0;
			return (2);
		}
	}
	if (len == 0)
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int		a;
	int		minus;

	a = 0;
	while (*nptr && (*nptr == '\n' || *nptr == '\t' || *nptr == ' ' ||
			*nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	minus = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	if (ft_atoibig(nptr, &minus) > 0)
		return (-1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		a = a * 10 + *nptr - '0';
		nptr++;
	}
	return (a * minus);
}
