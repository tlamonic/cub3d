/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepdda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:21:06 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:21:07 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	countres(double xx, double yy)
{
	if (fabs(xx) == 0)
		return (fabs(yy) + 0.000001);
	else if (fabs(yy) == 0)
		return (fabs(xx) + 0.000001);
	else if (fabs(xx) < fabs(yy))
		return (fabs(xx) + 0.000001);
	else
		return (fabs(yy) + 0.000001);
}

void	dostep1(double *c, double x, double y, double angle)
{
	double xx;
	double yy;
	double result;

	xx = (((int)x - x + 1) / cos(angle));
	yy = (((int)y - y + 1) / sin(angle));
	if ((angle > 0 && angle <= M_PI_2) ||\
	(angle > 0 + 2 * M_PI && angle <= M_PI_2 + 2 * M_PI))
		;
	else if (angle > M_PI_2 && angle < M_PI)
		xx = (x - (int)x) / (cos(correctangle(angle)));
	else if (angle <= -M_PI_2 + 2 * M_PI && angle >= M_PI)
	{
		xx = (x - (int)x) / (cos(correctangle(angle)));
		yy = (y - (int)y) / (sin(correctangle(angle)));
	}
	else
		yy = (y - (int)y) / (sin(correctangle(angle)));
	result = countres(xx, yy);
	*c = *c + result;
}
