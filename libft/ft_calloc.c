/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 05:53:00 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/22 14:00:34 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	nbytes;
	void			*ptr;

	nbytes = count * size;
	if (!(ptr = malloc(nbytes)))
		return (NULL);
	ft_memset(ptr, 0, nbytes);
	return (ptr);
}
