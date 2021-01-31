/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 06:29:13 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/09 18:00:56 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_gnbzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = 0;
		i++;
	}
}

char			*ft_strnew(size_t size)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_gnbzero(str, size + 1);
	return (str);
}

static int		ft_read_line(int fd, char **remainder)
{
	int			reader;
	char		*buffer;

	reader = 0;
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	while ((reader = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		*remainder = ft_gnstrjoin(*remainder, buffer);
	}
	free(buffer);
	return (1);
}

int				ft_fill_null(char **line)
{
	*line = ft_strnew(BUFFER_SIZE + 1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(ft_read_line(fd, &remainder)))
		return (-1);
	if (read(fd, 0, 0) == -1)
		return (-1);
	if (!remainder)
		return (ft_fill_null(line));
	if ((ft_gnstrchr(remainder, '\n')))
	{
		*line = ft_gnstrdup(remainder);
		remainder = ft_substr_n(remainder);
		return (1);
	}
	else
	{
		*line = ft_gnstrdup(remainder);
		remainder = ft_substr_n(remainder);
	}
	return (0);
}
