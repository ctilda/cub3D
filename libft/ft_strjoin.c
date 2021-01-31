/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 02:03:28 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/20 17:53:15 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*conc;
	size_t			i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!(conc = (char*)malloc(sizeof(*conc) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1 != '\0')
		conc[i++] = *s1++;
	while (*s2 != '\0')
		conc[i++] = *s2++;
	conc[i] = '\0';
	return (conc);
}
