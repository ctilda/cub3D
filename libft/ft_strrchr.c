/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:05:52 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/20 19:45:38 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;

	len = ft_strlen(str);
	if ((char)ch == '\0')
		return ((char *)str + len);
	while (len--)
	{
		if (str[len] == ch)
			return ((char *)str + len);
	}
	return (0);
}
