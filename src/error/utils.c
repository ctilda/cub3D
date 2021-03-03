/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:28:05 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 19:46:20 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int				xpm_correct(char *str, t_g *g, char *nstr, int fl)
{
	g->i = ft_strlen(str) - 1;
	g->j = ft_strlen(nstr) - 1;
	g->x = 0;
	while (g->x < g->j)
	{
		if (str[g->i] != nstr[g->j])
			(fl) ? ft_error(-12, g) : ft_error(-3, g);
		g->x++;
	}
	return (0);
}

void			ft_putstr_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void		free_arrays(t_g *g, int fl)
{
	int		i;
	int		k;

	k = 0;
	if (fl == 0)
		k = g->count;
	else if (fl == 1)
		k = g->heightm;
	i = 0;
	while (i < k)
	{
		(fl == 0 && g->texture[i]) ? free(g->texture[i]) : 0;
		(fl == 1 && g->map[i]) ? free(g->map[i]) : 0;
		i++;
	}
	(fl == 0 && g->texture) ? free(g->texture) : 0;
	(fl == 1 && g->map) ? free(g->map) : 0;
}

int				ft_free(t_g *g)
{
	(g->no) ? free(g->no) : 0;
	(g->so) ? free(g->so) : 0;
	(g->we) ? free(g->we) : 0;
	(g->ea) ? free(g->ea) : 0;
	(g->s) ? free(g->s) : 0;
	(g->k) ? free(g->k) : 0;
	exit(0);
	return (0);
}

int				ft_free_exit(t_g *g)
{
	(g->texture) ? free_arrays(g, 0) : 0;
	(g->map) ? free_arrays(g, 1) : 0;
	(g->no) ? free(g->no) : 0;
	(g->so) ? free(g->so) : 0;
	(g->we) ? free(g->we) : 0;
	(g->ea) ? free(g->ea) : 0;
	(g->s) ? free(g->s) : 0;
	(g->k) ? free(g->k) : 0;
	(g->sprite) ? free(g->sprite) : 0;
	(g->zbuffer) ? free(g->zbuffer) : 0;
	(g->spr.num) ? free(g->spr.num) : 0;
	(g->spr.dist) ? free(g->spr.dist) : 0;
	(g->img.img) ? free(g->img.img) : 0;
	exit(0);
	return (0);
}
