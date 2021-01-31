/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:57:34 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/20 18:10:12 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	if (src == 0)
		return (0);
	while (src[len] != '\0')
		len++;
	if (destsize == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < (destsize - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (len);
}
