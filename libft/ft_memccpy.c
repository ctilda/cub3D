/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 06:04:39 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/19 17:16:29 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int end_sym, size_t n)
{
	unsigned char		*src_c;
	unsigned char		*dest_c;
	size_t				i;

	i = 0;
	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		if (src_c[i] == (unsigned char)end_sym)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
