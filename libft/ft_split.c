/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 06:13:09 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/22 15:29:26 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char		*skip_delim(char *str, char c)
{
	while (*str == c && *str != '\0')
		str++;
	return (str);
}

static char		word_count(char *str, char c)
{
	size_t	count;

	count = 0;
	str = skip_delim(str, c);
	while (*str)
	{
		str = str + word_len(str, c);
		str = skip_delim(str, c);
		count++;
	}
	return (count);
}

static char		**filling_tab(char **tab, char *str, char c)
{
	size_t	i;

	i = 0;
	str = skip_delim(str, c);
	while (*str)
	{
		tab[i] = malloc(word_len(str, c) + 1);
		if (tab[i] == 0)
		{
			while (i--)
				free(tab[i]);
			return (0);
		}
		ft_strlcpy(tab[i], str, word_len(str, c) + 1);
		str = str + word_len(str, c);
		str = skip_delim(str, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;

	if (s == 0)
		return (NULL);
	tab = malloc((word_count((char*)s, c) + 1) * (sizeof(char*)));
	if (tab == 0)
		return (NULL);
	if (filling_tab(tab, (char*)s, c))
		return (tab);
	free(tab);
	return (NULL);
}
