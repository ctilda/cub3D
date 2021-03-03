/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:12:31 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:48:28 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_load_image(t_g *g, int *texture, char *path, t_img *img)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	img->img = mlx_xpm_file_to_image(g->mlx, path, &img->img_width, \
	&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, \
	&img->endian);
	while (++i < img->img_height)
	{
		j = -1;
		while (++j < img->img_width)
			texture[img->img_width * i + j] = img->data[img->img_width * i + j];
	}
	mlx_destroy_image(g->mlx, img->img);
}

void	load_texture(t_g *g)
{
	t_img	img;

	ft_load_image(g, g->texture[0], g->no, &img);
	ft_load_image(g, g->texture[1], g->so, &img);
	ft_load_image(g, g->texture[2], g->we, &img);
	ft_load_image(g, g->texture[3], g->ea, &img);
	ft_load_image(g, g->texture[4], g->s, &img);
	ft_load_image(g, g->texture[5], g->k, &img);
}
