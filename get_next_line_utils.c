/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 06:29:51 by ctilda            #+#    #+#             */
/*   Updated: 2020/12/09 17:53:34 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_gnstrlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char			*ft_gnstrchr(char *s, int c)
{
	char		*str;

	str = (char*)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == c)
		return (str);
	return (0);
}

char			*ft_substr_n(char *s)
{
	char		*new;
	int			j;
	int			i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * ((ft_gnstrlen(s) - i) + 1));
	i++;
	j = 0;
	while (s[i])
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(s);
	return (new);
}

char			*ft_gnstrjoin(char *s1, char *s2)
{
	char		*new;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = (char*)malloc(sizeof(*new) * ft_gnstrlen(s1) + ft_gnstrlen(s2) + 1);
	if (!new)
		return (NULL);
	if (s1)
		while (s1[i])
			new[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i])
			new[j++] = s2[i++];
	new[j] = '\0';
	free(s1);
	return (new);
}

char			*ft_gnstrdup(char *s1)
{
	int			i;
	char		*str;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
