/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:00:04 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:53:04 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parsing_map(char *av, t_g *g)
{
	int		fd;
	char	*line;

	if (!(fd = open(av, O_RDONLY)))
		ft_error(-2, g);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!(ft_strchr("FRCKNEWS", line[0])))
			g->heightm++;
		free(line);
	}
	free(line);
	g->heightm++;
	close(fd);
}

void	parse_arr(t_g *st, char c)
{
	int		i;

	i = 0;
	st->str++;
	while (i < 3)
	{
		while (*st->str == ',' || *st->str == ' ')
			st->str++;
		while (*st->str >= '0' && *st->str <= '9')
		{
			if (c == 'c')
				st->c[i] = st->c[i] * 10 + (*st->str - '0');
			else if (c == 'f')
				st->f[i] = st->f[i] * 10 + (*st->str - '0');
			st->str++;
		}
		i++;
	}
}

void	ft_navigation(t_g *g, char c)
{
	if (c == 'W' || c == 'E')
	{
		g->dirx = 0;
		g->diry = (c == 'W') ? -1 : 1;
		g->planex = (c == 'W') ? -0.66 : 0.66;
		g->planey = 0;
	}
	if (c == 'N' || c == 'S')
	{
		g->dirx = (c == 'N') ? -1 : 1;
		g->diry = 0;
		g->planex = 0;
		g->planey = (c == 'N') ? 0.66 : -0.66;
	}
}
