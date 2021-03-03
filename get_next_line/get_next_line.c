/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:38:53 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/25 12:24:08 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_read(int fd, char *str, char *buf)
{
	int			res;

	res = 1;
	while (res != 0 && !ft_return(str))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return ((char*)-1);
		}
		buf[res] = '\0';
		str = ft_join(str, buf);
	}
	free(buf);
	if (!str)
		return (NULL);
	return (str);
}

int				get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			res;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	str = ft_read(fd, str, buf);
	if (str == (char*)-1)
		return (-1);
	*line = ft_dup(str);
	str = ft_ndup(str);
	if (!str)
	{
		free(str);
		return (0);
	}
	return (1);
}
