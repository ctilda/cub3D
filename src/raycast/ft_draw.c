/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:06:18 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:46:18 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw(t_g *g)
{
	g->i = -1;
	g->j = -1;
	while (++g->i < g->winh)
	{
		g->j = -1;
		while (++g->j < g->winw)
			g->img.data[g->i * g->winw + g->j] = g->buf[g->i][g->j];
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	correct_wh(t_g *g)
{
	if (g->winw == 0 || g->winh == 0)
		ft_error(-13, g);
	(g->winw > MAX_DISPLAY_W) ? g->winw = MAX_DISPLAY_W : 0;
	(g->winh > MAX_DISPLAY_H) ? g->winh = MAX_DISPLAY_H : 0;
}

void	ft_window(t_g g)
{
	g.win = mlx_new_window(g.mlx, g.winw, g.winh, \
	"The Game");
	g.img.img = mlx_new_image(g.mlx, g.winw, g.winh);
	g.img.data = (int *)mlx_get_data_addr(g.img.img, &g.img.bpp, \
	&g.img.size_l, &g.img.endian);
	if (g.save)
	{
		start_app(&g);
		save_bmp(&g);
	}
	mlx_loop_hook(g.mlx, &start_app, &g);
	mlx_hook(g.win, 2, 0, &press_k, &g);
	mlx_hook(g.win, 3, 0, &reset_k, &g);
	mlx_hook(g.win, 17, 1L << 17, ft_free_exit, &g);
	mlx_loop(g.mlx);
}
