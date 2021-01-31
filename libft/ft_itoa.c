/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:28:38 by ctilda            #+#    #+#             */
/*   Updated: 2020/11/20 17:41:10 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_len(n);
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		j = 1;
	}
	else
		j = 0;
	while (i-- > j)
	{
		str[i] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n = n / 10;
	}
	return (str);
}
