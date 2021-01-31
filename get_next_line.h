/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 06:30:29 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/09 17:48:08 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1
# endif

size_t		ft_gnstrlen(const	char *s);
char		*ft_gnstrchr(char	*s, int c);
char		*ft_gnstrjoin(char *s1, char *s2);
char		*ft_gnstrdup(char *s);
char		*ft_substr_n(char *s);
int			get_next_line(int fd, char **line);
void		ft_gnbzero(void *s, size_t n);
char		*ft_strnew(size_t size);

#endif
