/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:01:52 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:51:47 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void		sprite_correct(t_g *g)
{
	int	j;

	j = 0;
	while (g->numspr > j)
	{
		check_close_map(g->sprite[j].x - 0.5, g->sprite[j].y \
		- 0.5, g, g->heightm);
		j++;
	}
}

void			ft_sprites(t_g *g)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (i < g->heightm)
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '2' || g->map[i][j] == '3')
			{
				g->sprite[k].x = i + 0.5;
				g->sprite[k].y = j + 0.5;
				(g->map[i][j] == '2') ? g->sprite[k].texture = 4 : 0;
				(g->map[i][j] == '3') ? g->sprite[k].texture = 5 : 0;
				g->map[i][j] = '0';
				k++;
			}
			j++;
		}
		i++;
	}
	sprite_correct(g);
}

void			sort_num(t_pair *num, int count)
{
	t_pair	sprites;
	int		i;
	int		j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			if (num[j].first > num[j + 1].first)
			{
				sprites.second = num[j].second;
				sprites.first = num[j].first;
				num[j].second = num[j + 1].second;
				num[j].first = num[j + 1].first;
				num[j + 1].second = sprites.second;
				num[j + 1].first = sprites.first;
			}
		}
	}
}

void			sortspr(int *num, float *dist, int count)
{
	t_pair	*sprites;
	int		i;

	i = -1;
	sprites = (t_pair*)malloc(sizeof(t_pair) * count);
	while (++i < count)
	{
		sprites[i].second = num[i];
		sprites[i].first = dist[i];
	}
	sort_num(sprites, count);
	i = -1;
	while (++i < count)
	{
		num[i] = sprites[count - i - 1].second;
		dist[i] = sprites[count - i - 1].first;
	}
	free(sprites);
}
