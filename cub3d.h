/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:16:42 by tlamonic          #+#    #+#             */
/*   Updated: 2020/09/09 17:48:42 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef	struct	s_map
{
	char		*EA;
	char		*WE;
	char		*SO;
	char		*NO;
	char		*S;
	int			res[2];
	int			F[3];
	int			C[3];
}				t_map;

#endif
