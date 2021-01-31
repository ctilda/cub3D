/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 07:17:46 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/20 19:31:04 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_c;
	unsigned char	c_c;
	int				i;

	i = 0;
	s_c = (unsigned char *)s;
	c_c = (unsigned char)c;
	while (n--)
	{
		if (s_c[i] == c_c)
			return (s_c + i);
		i++;
	}
	return (NULL);
}
