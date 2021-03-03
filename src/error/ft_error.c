/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:56:46 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:30:07 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void			ft_error(int x, t_g *g)
{
	(x == -1) ? ft_putstr_err("Error\ntrying to try memory!") : 0;
	(x == -2) ? ft_putstr_err("Error\ncan not open the file!") : 0;
	(x == -3) ? ft_putstr_err("Error\nMap extension is incorrect!") : 0;
	(x == -4) ? ft_putstr_err("Error\nInvalid number of arguments!") : 0;
	(x == -5) ? ft_putstr_err("Error\nFlags error!") : 0;
	(x == -6) ? ft_putstr_err("Error\nDuplicate flag!") : 0;
	(x == -7) ? ft_putstr_err("Error\nPlease, write '--save'") : 0;
	(x == -8) ? ft_putstr_err("Error\ncan't open the textures!") : 0;
	(x == -9) ? ft_putstr_err("Error\nDublicate player position!") : 0;
	(x == -10) ? ft_putstr_err("Error\ncan't creating mlx!") : 0;
	(x == -11) ? ft_putstr_err("Error\nNo player positions!") : 0;
	(x == -12) ? ft_putstr_err("Error\nInvalid texture extension!") : 0;
	(x == -13) ? ft_putstr_err("Error\ncalculating resolution!") : 0;
	(x == -14) ? ft_putstr_err("Error\nCan't create screenshot!") : 0;
	(x == -15) ? ft_putstr_err("Error\nMap error") : 0;
	(x == -16) ? ft_putstr_err("Error\nIndicate map!") : 0;
	(x == -17) ? ft_putstr_err("Error\nIndicate try arguments!") : 0;
	ft_free(g);
}

void			ft_parse_error(t_g *g)
{
	char *s;

	s = ".xpm";
	if (!g->no || !g->so || !g->we || !g->ea \
		|| !g->s || !g->k)
		ft_error(-5, g);
	xpm_correct(g->no, g, s, 1);
	xpm_correct(g->so, g, s, 1);
	xpm_correct(g->we, g, s, 1);
	xpm_correct(g->ea, g, s, 1);
	xpm_correct(g->s, g, s, 1);
	xpm_correct(g->k, g, s, 1);
	if ((open(g->no, O_RDONLY) == -1) || (open(g->so, O_RDONLY) == -1) \
		|| (open(g->we, O_RDONLY) == -1) || (open(g->ea, O_RDONLY) \
		== -1) || (open(g->s, O_RDONLY) == -1)  \
		|| (open(g->k, O_RDONLY) == -1))
		ft_error(-8, g);
	if (!g->winw && !g->winh)
		ft_error(-13, g);
}

static	void	check_symbols(t_g *g)
{
	g->i = -1;
	while (++g->i < g->heightm)
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			if (g->map[g->i][g->j] != '1' && g->map[g->i][g->j] != '2'\
			&& g->map[g->i][g->j] != '3' && g->map[g->i][g->j] != '0'\
			&& g->map[g->i][g->j] != ' ')
				ft_error(-15, g);
			g->j++;
		}
	}
}

void			check_close(t_g *g)
{
	check_close_map(g->posx - 0.5, g->posy \
	- 0.5, g, g->heightm);
	g->i = -1;
	while (++g->i < g->heightm)
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			if (g->map[g->i][g->j] == 'Z')
				g->map[g->i][g->j] = '0';
			if (g->map[g->i][g->j] == 'M')
				g->map[g->i][g->j] = '2';
			if (g->map[g->i][g->j] == 'N')
				g->map[g->i][g->j] = '3';
			g->j++;
		}
	}
	check_symbols(g);
}

void			check_close_map(int x, int y, t_g *g, int height)
{
	if (x > height - 1 || x < 0 || y > (int)(ft_strlen(g->map[x])) \
	- 1 || y < 0 || g->map[x][y] == ' ')
		ft_error(-15, g);
	if (g->map[x][y] == '1' || g->map[x][y] == 'Z' \
	|| g->map[x][y] == 'N' || g->map[x][y] == 'M')
		return ;
	if (g->map[x][y] != '1' && g->map[x][y] != '2' && \
	g->map[x][y] != '3' && g->map[x][y] != '0')
		ft_error(-15, g);
	if (g->map[x][y] == '0')
		g->map[x][y] = 'Z';
	if (g->map[x][y] == '2')
		g->map[x][y] = 'M';
	if (g->map[x][y] == '3')
		g->map[x][y] = 'N';
	check_close_map(x + 1, y, g, height);
	check_close_map(x + 1, y - 1, g, height);
	check_close_map(x - 1, y, g, height);
	check_close_map(x - 1, y - 1, g, height);
	check_close_map(x, y + 1, g, height);
	check_close_map(x, y - 1, g, height);
}
