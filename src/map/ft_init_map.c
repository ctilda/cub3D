/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:54:02 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:29:43 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void			struct_init(t_g *g)
{
	g->posx = 0.0;
	g->posy = 0.0;
	g->numspr = 0;
	g->count = 0;
	g->key_a = 0;
	g->key_w = 0;
	g->key_s = 0;
	g->key_d = 0;
	g->key_left = 0;
	g->key_right = 0;
	g->key_esc = 0;
	g->n = 0;
}

static void		player_pos(char c, t_g *g, int i, int j)
{
	if ((c == 'N' || c == 'E' || c == 'W' || c == 'S') && !g->posx)
	{
		ft_navigation(g, c);
		g->posx = (float)j + 0.5;
		g->posy = (float)i + 0.5;
	}
	else
		ft_error(-9, g);
}

char			*ft_convert(char *line, t_g *g, int j)
{
	int		i;
	int		c;
	char	*new;

	i = 0;
	c = ft_strlen(line) + 1;
	if (!(new = (char*)malloc(c * sizeof(char))))
		ft_error(-1, g);
	while (line[i])
	{
		if ((line[i] == 'N' || line[i] == 'E' || line[i] == 'W' \
		|| line[i] == 'S'))
		{
			player_pos(line[i], g, i, j);
			line[i] = '0';
		}
		new[i] = line[i];
		if (new[i] == '2' || new[i] == '3')
			g->numspr++;
		i++;
	}
	new[c - 1] = '\0';
	new[c] = '\0';
	return (new);
}

void			make_map(t_list **head, t_g *g)
{
	int		i;
	t_list	*tmp;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		g->map[i] = ft_convert(tmp->content, g, i);
		tmp = tmp->next;
		i++;
	}
}

void			game_loop(t_g *g, char *str)
{
	g->count = -2;
	xpm_correct(str, g, ".cub", 0);
	if (open(str, O_RDONLY) == -1)
		ft_error(-2, g);
	struct_init(g);
	if (!(g->mlx = mlx_init()))
		ft_error(-10, g);
	parsing_map(str, g);
	if (!(g->map = (char**)malloc((g->heightm + 1) * sizeof(char*))))
		ft_error(-1, g);
	parsing_flags(str, g);
	ft_parse_error(g);
	correct_wh(g);
	if (!g->posx || !g->posy)
		ft_error(-11, g);
	ft_for_malloc(g);
	load_texture(g);
	check_close(g);
	ft_window(*g);
}
