/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:10:40 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:12:01 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	ft_sprmalloc(t_g *g)
{
	if (!(g->spr.num = (int*)malloc(sizeof(int) * g->numspr)))
		ft_error(-1, g);
	if (!(g->spr.dist = (float*)malloc(sizeof(float) * g->numspr)))
		ft_error(-1, g);
}

static void	ft_for_malloc2(t_g *g)
{
	int i;

	i = -1;
	if (!(g->texture = (int **)malloc(sizeof(int *) * g->count)))
		ft_error(-1, g);
	while (++i < g->count)
		if (!(g->texture[i] = (int *)malloc(sizeof(int) * (TH \
		* TW))))
			ft_error(-1, g);
	i = 0;
	while (i < g->count)
	{
		ft_bzero(g->texture[i], TH * TW);
		i++;
	}
	ft_sprmalloc(g);
}

void		ft_for_malloc(t_g *g)
{
	int i;

	i = -1;
	if (!(g->sprite = (t_sprite*)malloc(sizeof(t_sprite) \
	* g->numspr)))
		ft_error(-1, g);
	ft_sprites(g);
	if (!(g->buf = (int**)malloc(sizeof(int*) * g->winh)))
		ft_error(-1, g);
	while (++i < g->winh)
		if (!(g->buf[i] = (int*)malloc(g->winw * sizeof(int))))
			ft_error(-1, g);
	if (!(g->zbuffer = (float*)malloc(sizeof(float) * g->winw)))
		ft_error(-1, g);
	i = 0;
	while (i < g->winh)
	{
		ft_bzero(g->buf[i], g->winw);
		i++;
	}
	ft_for_malloc2(g);
}
