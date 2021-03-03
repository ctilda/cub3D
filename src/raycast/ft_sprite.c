/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:13 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/25 11:31:50 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	spr_calculate(t_g *g, int i)
{
	g->spr.sprx = g->sprite[g->spr.num[i]].x - g->posx;
	g->spr.spry = g->sprite[g->spr.num[i]].y - g->posy;
	g->spr.distce = 1.0 / (g->planex * g->diry - g->dirx * g->planey);
	g->spr.trx = g->spr.distce * (g->diry * g->spr.sprx - g->dirx \
	* g->spr.spry);
	g->spr.trry = g->spr.distce * (-g->planey * g->spr.sprx + g->planex \
	* g->spr.spry);
	g->spr.scrnx = (int)((g->winw / 2) * (1 + g->spr.trx \
	/ g->spr.trry));
	g->spr.mscrnx = (int)(0.0 / g->spr.trry);
	g->spr.height = (int)fabs((g->winh / g->spr.trry) / 1);
	g->spr.dstry = -g->spr.height / 2 + g->winh / 2 + g->spr.mscrnx;
}

static	void	spr_conditions(t_g *g)
{
	if (g->spr.dstry < 0)
		g->spr.dstry = 0;
	g->spr.dendy = (g->spr.height / 2) + (g->winh / 2) + g->spr.mscrnx;
	if (g->spr.dendy >= g->winh)
		g->spr.dendy = g->winh - 1;
	g->spr.width = (int)fabs((g->winh / g->spr.trry) / 1);
	g->spr.dstrx = -g->spr.width / 2 + g->spr.scrnx;
	if (g->spr.dstrx < 0)
		g->spr.dstrx = 0;
	g->spr.dendx = g->spr.width / 2 + g->spr.scrnx;
	if (g->spr.dendx >= g->winw)
		g->spr.dendx = g->winw - 1;
}

static	void	spr_tex(t_g *g, int i)
{
	int j;
	int k;

	k = 0;
	j = g->spr.dstrx - 1;
	while (++j < g->spr.dendx)
	{
		g->spr.tex = (int)((256 * (j - (-g->spr.width / 2 + g->spr.scrnx))\
		* TW / g->spr.width) / 256);
		if (g->spr.trry > 0 && j > 0 && j < g->winw && g->spr.trry <\
		g->zbuffer[j])
		{
			k = g->spr.dstry - 1;
			while (++k < g->spr.dendy)
			{
				g->spr.d = (k - g->spr.mscrnx) * 256 - g->winh \
				* 128 + g->spr.height * 128;
				g->spr.texy = ((g->spr.d * TH) / g->spr.height) / 256;
				g->spr.color = g->texture[g->sprite[g->spr.num[i]].\
				texture][TW * g->spr.texy + g->spr.tex];
				if ((g->spr.color & 0x00FFFFFF) != 0)
					g->buf[k][j] = g->spr.color;
			}
		}
	}
}

void			ft_read_spr(t_g *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = -1;
	while (++i < g->numspr)
	{
		g->spr.num[i] = i;
		g->spr.dist[i] = ((g->posx - g->sprite[i].x) *\
		(g->posx - g->sprite[i].x) + (g->posy - g->sprite[i].y) \
		* (g->posy - g->sprite[i].y));
	}
	sortspr(g->spr.num, g->spr.dist, g->numspr);
	i = -1;
	while (++i < g->numspr)
	{
		spr_calculate(g, i);
		spr_conditions(g);
		spr_tex(g, i);
	}
}
