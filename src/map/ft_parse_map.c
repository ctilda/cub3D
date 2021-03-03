/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:55:15 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:41:15 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static char		*ft_parse(char *line, t_g *g)
{
	char	*nstr;

	while (*line == 'N' || *line == 'O' || *line == 'S' || *line == 'W' \
		|| *line == 'E' || *line == 'A' || *line == ' ' || *line == 'F' \
		|| *line == 'C' || *line == 'K')
		line++;
	g->count++;
	if (!(nstr = ft_strdup(line)))
		ft_error(-1, g);
	return (nstr);
}

static int		parse_num(t_g *g, int fl)
{
	int	num;

	num = 0;
	while (*g->str == 'R' || *g->str == ' ' || *g->str == ',')
		g->str++;
	if (fl == 0)
	{
		while (*g->str >= '0' && *g->str <= '9')
		{
			num = num * 10 + (*g->str - '0');
			g->str++;
		}
	}
	else
	{
		if (g->winw && g->winh && *g->str >= '0' && *g->str <= '9')
			return (-1);
	}
	return (num);
}

void			parsing_flags_rd(char *line, t_g *g)
{
	if (line[0] == 'E' && line[1] == 'A' && g->ea)
		ft_error(-6, g);
	else if (line[0] == 'E' && line[1] == 'A' && !g->ea)
		g->ea = ft_parse(line, g);
	if (line[0] == 'S' && line[1] == ' ' && g->s)
		ft_error(-6, g);
	else if (line[0] == 'S' && line[1] == ' ' && !g->s)
		g->s = ft_parse(line, g);
	if (line[0] == 'K' && line[1] == ' ' && g->k)
		ft_error(-6, g);
	else if (line[0] == 'K' && line[1] == ' ' && !g->k)
		g->k = ft_parse(line, g);
	(line[0] == 'F') ? parse_arr(g, 'f') : 0;
	(line[0] == 'C') ? parse_arr(g, 'c') : 0;
}

void			parsing_flags_nd(char *line, t_g *g)
{
	if (line[0] == 'R' && (g->winw || g->winh))
		ft_error(-6, g);
	else if (line[0] == 'R' && (!g->winw && !g->winh))
	{
		g->winw = parse_num(g, 0);
		g->winh = parse_num(g, 0);
		if (parse_num(g, 1) == -1)
			ft_error(-13, g);
	}
	if (line[0] == 'N' && line[1] == 'O' && g->no)
		ft_error(-6, g);
	else if (line[0] == 'N' && line[1] == 'O' && !g->no)
		g->no = ft_parse(line, g);
	if (line[0] == 'S' && line[1] == 'O' && g->so)
		ft_error(-6, g);
	else if (line[0] == 'S' && line[1] == 'O' && !g->so)
		g->so = ft_parse(line, g);
	if (line[0] == 'W' && line[1] == 'E' && g->we)
		ft_error(-6, g);
	else if (line[0] == 'W' && line[1] == 'E' && !g->we)
		g->we = ft_parse(line, g);
	parsing_flags_rd(line, g);
}

void			parsing_flags(char *av, t_g *g)
{
	int		fd;
	char	*line;
	int		i;

	(!(fd = open(av, O_RDONLY))) ? ft_error(-2, g) : 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strchr("NEWSFRCK", line[0]))
		{
			g->str = line;
			parsing_flags_nd(line, g);
			(g->count == 8 && g->n == 1) ? ft_error(-15, g) : 0;
		}
		else
		{
			g->n = 1;
			g->map[i] = ft_convert(line, g, i);
			i++;
		}
		free(line);
	}
	g->map[i] = ft_convert(line, g, i);
	free(line);
	close(fd);
}
