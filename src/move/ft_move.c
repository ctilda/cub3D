/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:19:40 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/25 12:05:04 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void		key_cont(t_g *g)
{
	if (g->key_w)
	{
		if (g->map[(int)(g->posx + g->dirx * MVSPEED)]\
			[(int)(g->posy)] == '0')
			g->posx += g->dirx * MVSPEED;
		if (g->map[(int)(g->posx)][(int)(g->posy + g->diry \
			* MVSPEED)] == '0')
			g->posy += g->diry * MVSPEED;
	}
	if (g->key_s)
	{
		if (g->map[(int)(g->posx - g->dirx * MVSPEED)]\
			[(int)(g->posy)] == '0')
			g->posx -= g->dirx * MVSPEED;
		if (g->map[(int)(g->posx)][(int)(g->posy - g->diry \
			* MVSPEED)] == '0')
			g->posy -= g->diry * MVSPEED;
	}
}

void			key_da(t_g *g)
{
	if (g->key_a)
	{
		if (g->map[(int)(g->posx - g->planex * MVSPEED)]\
			[(int)(g->posy)] == '0')
			g->posx -= g->planex * MVSPEED;
		if (g->map[(int)(g->posx)][(int)(g->posy - g->planey \
			* MVSPEED)] == '0')
			g->posy -= g->planey * MVSPEED;
	}
	if (g->key_d)
	{
		if (g->map[(int)(g->posx + g->planex * MVSPEED)]\
			[(int)(g->posy)] == '0')
			g->posx += g->planex * MVSPEED;
		if (g->map[(int)(g->posx)][(int)(g->posy + g->planey \
			* MVSPEED)] == '0')
			g->posy += g->planey * MVSPEED;
	}
	(g->key_esc) ? exit(0) : 0;
	key_cont(g);
}

void			keys(t_g *g)
{
	double olddirx;
	double oldplanex;

	if (g->key_right)
	{
		olddirx = g->dirx;
		g->dirx = g->dirx * cos(-RTSPEED) - g->diry *\
		sin(-RTSPEED);
		g->diry = olddirx * sin(-RTSPEED) + g->diry *\
		cos(-RTSPEED);
		oldplanex = g->planex;
		g->planex = g->planex * cos(-RTSPEED) - g->planey \
		* sin(-RTSPEED);
		g->planey = oldplanex * sin(-RTSPEED) + g->planey \
		* cos(-RTSPEED);
	}
	key_l(g);
}

void			key_l(t_g *g)
{
	double olddirx;
	double oldplanex;

	if (g->key_left)
	{
		olddirx = g->dirx;
		g->dirx = g->dirx * cos(RTSPEED) - g->diry \
		* sin(RTSPEED);
		g->diry = olddirx * sin(RTSPEED) + g->diry \
		* cos(RTSPEED);
		oldplanex = g->planex;
		g->planex = g->planex * cos(RTSPEED) - g->planey \
		* sin(RTSPEED);
		g->planey = oldplanex * sin(RTSPEED) + g->planey \
		* cos(RTSPEED);
	}
	key_da(g);
}
