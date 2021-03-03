/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:07:54 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/25 11:30:40 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	bmpt(t_g *g)
{
	unsigned char	buf[14];

	g->bmp.i = 0;
	ft_bzero(buf, 14);
	buf[0] = (unsigned char)('B');
	buf[1] = (unsigned char)('M');
	g->bmp.tmp = 4 * (g->winw * g->winh) + 14 + 40;
	buf[2] = (unsigned char)(g->bmp.tmp % 256);
	buf[3] = (unsigned char)(g->bmp.tmp / 256 % 256);
	buf[4] = (unsigned char)(g->bmp.tmp / 256 / 256 % 256);
	buf[5] = (unsigned char)(g->bmp.tmp / 256 / 256 / 256);
	buf[10] = (unsigned char)(54);
	write(g->bmp.fd, buf, 14);
}

static void	bmpi(t_g *g)
{
	unsigned char	buf[40];

	g->bmp.i = 0;
	while (g->bmp.i < 40)
		buf[g->bmp.i++] = 0;
	buf[0] = (unsigned char)(40);
	buf[4] = (unsigned char)(g->winw % 256);
	buf[5] = (unsigned char)(g->winw / 256 % 256);
	buf[6] = (unsigned char)(g->winw / 256 / 256 % 256);
	buf[7] = (unsigned char)(g->winw / 256 / 256 / 256);
	buf[8] = (unsigned char)(g->winh % 256);
	buf[9] = (unsigned char)(g->winh / 256 % 256);
	buf[10] = (unsigned char)(g->winh / 256 / 256 % 256);
	buf[11] = (unsigned char)(g->winh / 256 / 256 / 256);
	buf[12] = (unsigned char)(1);
	buf[14] = (unsigned char)(32);
	write(g->bmp.fd, buf, 40);
}

static void	bmpd(t_g *g)
{
	unsigned char	buf[4];

	g->bmp.i = g->winh - 1;
	while (g->bmp.i >= 0)
	{
		g->bmp.j = -1;
		while (++g->bmp.j < g->winw)
		{
			g->bmp.tmp = g->img.data[g->bmp.j + g->bmp.i \
			* g->winw];
			buf[0] = (unsigned char)(g->bmp.tmp % 256);
			buf[1] = (unsigned char)(g->bmp.tmp / 256 % 256);
			buf[2] = (unsigned char)(g->bmp.tmp / 256 / 256);
			buf[3] = (unsigned char)(0);
			write(g->bmp.fd, buf, 4);
		}
		g->bmp.i--;
	}
}

int			save_bmp(t_g *g)
{
	if (!(g->bmp.fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0700)))
		ft_error(-14, g);
	bmpt(g);
	bmpi(g);
	bmpd(g);
	close(g->bmp.fd);
	ft_free(g);
	return (0);
}
