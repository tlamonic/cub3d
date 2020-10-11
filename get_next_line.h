/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamonic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:17:06 by tlamonic          #+#    #+#             */
/*   Updated: 2020/10/11 19:17:07 by tlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
char		*ft_strjoinn(char *s1, char *s2);
char		*ft_substrr(char *s, unsigned int start, size_t len, int n);
size_t		ft_strlenn(const char *s);

#endif
