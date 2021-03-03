/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:07:08 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:39:45 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	wall_dist(t_g *g)
{
	if (g->rct.raydirx < 0)
	{
		g->rct.stepx = -1;
		g->rct.sdistx = (g->posx - g->rct.mpx) * g->rct.ddistx;
	}
	else
	{
		g->rct.stepx = 1;
		g->rct.sdistx = (g->rct.mpx + 1.0 - g->posx) * g->rct.ddistx;
	}
	if (g->rct.raydiry < 0)
	{
		g->rct.stepy = -1;
		g->rct.sdisty = (g->posy - g->rct.mpy) * g->rct.ddisty;
	}
	else
	{
		g->rct.stepy = 1;
		g->rct.sdisty = (g->rct.mpy + 1.0 - g->posy) * g->rct.ddisty;
	}
}

static	void	is_hit(t_g *g)
{
	g->rct.hit = 0;
	while (g->rct.hit == 0)
	{
		if (g->rct.sdistx < g->rct.sdisty)
		{
			g->rct.sdistx += g->rct.ddistx;
			g->rct.mpx += g->rct.stepx;
			if (g->rct.raydirx < 0)
				g->rct.side = 0;
			else
				g->rct.side = 2;
		}
		else
		{
			g->rct.sdisty += g->rct.ddisty;
			g->rct.mpy += g->rct.stepy;
			if (g->rct.raydiry < 0)
				g->rct.side = 1;
			else
				g->rct.side = 3;
		}
		if (g->map[g->rct.mpx][g->rct.mpy] == '1')
			g->rct.hit = 1;
	}
}

static	void	calculate_walls(t_g *g)
{
	if (g->rct.side == 0 || g->rct.side == 2)
		g->rct.pwalld = (float)(g->rct.mpx - g->posx \
		+ (1 - g->rct.stepx) / 2) / g->rct.raydirx;
	else
		g->rct.pwalld = (double)(g->rct.mpy - g->posy \
		+ (1 - g->rct.stepy) / 2) / g->rct.raydiry;
	g->rct.lheight = (int)(g->winh / g->rct.pwalld);
	g->rct.dstart = -g->rct.lheight / 2 + g->winh / 2;
	(g->rct.dstart < 0) ? g->rct.dstart = 0 : 0;
	g->rct.dend = g->rct.lheight / 2 + g->winh / 2;
	(g->rct.dend >= g->winh) ? g->rct.dend = g->winh - 1 : 0;
	g->rct.tnum = g->map[g->rct.mpx][g->rct.mpy] - '0' - 1;
	if (g->rct.side == 0 || g->rct.side == 2)
		g->rct.xwall = g->posy + g->rct.pwalld * g->rct.raydiry;
	else
		g->rct.xwall = g->posx + g->rct.pwalld * g->rct.raydirx;
	g->rct.xwall -= floor((g->rct.xwall));
	g->rct.texx = (int)(g->rct.xwall * (float)TW);
	if ((g->rct.side == 0 || g->rct.side == 2) && g->rct.raydirx > 0)
		g->rct.texx = TW - g->rct.texx - 1;
	if ((g->rct.side == 1 || g->rct.side == 3) && g->rct.raydiry < 0)
		g->rct.texx = TW - g->rct.texx - 1;
}

static	void	walls_calc_text(t_g *g, int x)
{
	int y;

	y = 0;
	if ((g->rct.side == 0 || g->rct.side == 2) && g->rct.raydirx >= 0)
		g->rct.tnum = 1;
	else if ((g->rct.side == 0 || g->rct.side == 2) && g->rct.raydirx < 0)
		g->rct.tnum = 0;
	else if ((g->rct.side == 1 || g->rct.side == 3) && g->rct.raydiry < 0)
		g->rct.tnum = 2;
	else
		g->rct.tnum = 3;
	g->rct.step = 1.0 * TH / g->rct.lheight;
	g->rct.tpos = (g->rct.dstart - g->winh / 2 +\
	g->rct.lheight / 2) * g->rct.step;
	y = g->rct.dstart - 1;
	while (++y < g->rct.dend)
	{
		g->rct.texy = (int)g->rct.tpos & (TH - 1);
		g->rct.tpos += g->rct.step;
		g->buf[y][x] = g->texture[g->rct.tnum][TH *\
		g->rct.texy + g->rct.texx];
	}
	g->zbuffer[x] = g->rct.pwalld;
}

void			walls(t_g *g)
{
	int x;

	x = -1;
	floor_ceiling(g);
	while (++x < g->winw)
	{
		g->rct.cam = 2 * x / (float)g->winw - 1;
		g->rct.raydirx = g->dirx + g->planex * g->rct.cam;
		g->rct.raydiry = g->diry + g->planey * g->rct.cam;
		g->rct.mpx = (int)g->posx;
		g->rct.mpy = (int)g->posy;
		g->rct.ddistx = fabs(1 / g->rct.raydirx);
		g->rct.ddisty = fabs(1 / g->rct.raydiry);
		g->rct.hit = 0;
		wall_dist(g);
		is_hit(g);
		calculate_walls(g);
		walls_calc_text(g, x);
	}
	ft_read_spr(g);
}
