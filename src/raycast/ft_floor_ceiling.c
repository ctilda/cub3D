/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:07:10 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:27:49 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	fc_width(t_g *g, int y)
{
	g->j = 0;
	while (++g->j < g->winw)
	{
		g->fc.cellx = (int)(g->fc.floorx);
		g->fc.celly = (int)(g->fc.floory);
		g->fc.tx = (int)(TW * (g->fc.floorx - g->fc.cellx)) & (TW - 1);
		g->fc.ty = (int)(TH * (g->fc.floory - g->fc.celly)) & (TH - 1);
		g->fc.floorx += g->fc.stepx;
		g->fc.floory += g->fc.stepy;
		g->fc.color = RGB(g->f[0], g->f[1], g->f[2]);
		g->buf[y][g->j] = g->fc.color;
		g->fc.color = RGB(g->c[0], g->c[1], g->c[2]);
		g->buf[g->winh - y - 1][g->j] = g->fc.color;
	}
}

void		floor_ceiling(t_g *g)
{
	g->i = g->winh / 2 + 1;
	while (g->i < g->winh)
	{
		g->fc.rayx0 = g->dirx - g->planex;
		g->fc.rayy0 = g->diry - g->planey;
		g->fc.rayx1 = g->dirx + g->planex;
		g->fc.rayy1 = g->diry + g->planey;
		g->fc.p = g->i - g->winh / 2;
		g->fc.posz = 0.5 * g->winh;
		g->fc.rdist = g->fc.posz / g->fc.p;
		g->fc.stepx = g->fc.rdist * (g->fc.rayx1 - g->fc.rayx0) \
		/ g->winw;
		g->fc.stepy = g->fc.rdist * (g->fc.rayy1 - g->fc.rayy0) \
		/ g->winw;
		g->fc.floorx = g->posx + g->fc.rdist * g->fc.rayx0;
		g->fc.floory = g->posy + g->fc.rdist * g->fc.rayy0;
		fc_width(g, g->i);
		g->i++;
	}
}
