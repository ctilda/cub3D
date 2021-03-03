/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:39:11 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/25 12:07:25 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t		ft_len(char *str, int f);
char		*ft_dup(char *str);
char		*ft_join(char *s1, char *s2);
int			ft_return(char *str);
char		*ft_ndup(char *str);
int			get_next_line(int fd, char **line);

#endif
