/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:16:55 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/25 11:32:33 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int				press_k(int key, t_g *g)
{
	if (key == K_ESC)
		ft_free_exit(g);
	else if (key == K_W)
		g->key_w = 1;
	else if (key == K_LEFT)
		g->key_left = 1;
	else if (key == K_S)
		g->key_s = 1;
	else if (key == K_RIGHT)
		g->key_right = 1;
	else if (key == K_A)
		g->key_a = 1;
	else if (key == K_D)
		g->key_d = 1;
	return (0);
}

int				reset_k(int key, t_g *g)
{
	if (key == K_W)
		g->key_w = 0;
	else if (key == K_LEFT)
		g->key_left = 0;
	else if (key == K_S)
		g->key_s = 0;
	else if (key == K_RIGHT)
		g->key_right = 0;
	else if (key == K_A)
		g->key_a = 0;
	else if (key == K_D)
		g->key_d = 0;
	else if (key == K_ESC)
		ft_free_exit(g);
	return (0);
}
