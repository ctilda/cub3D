/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:47:30 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:54:34 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_g		g;

	if (ac == 3)
	{
		if (!(ft_strncmp(av[2], "--save", 7)))
		{
			g.save = 1;
			game_loop(&g, av[1]);
		}
		else
			ft_error(-7, &g);
	}
	else if (ac == 1)
		ft_error(-16, &g);
	else if (ac == 2)
		game_loop(&g, av[1]);
	else
		ft_error(-17, &g);
	return (0);
}
