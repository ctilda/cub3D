/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:00:35 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/27 20:44:09 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>

# define TW 64
# define TH 64

# define K_LEFT 123
# define K_RIGHT 124
# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13
# define K_ESC 53

# define MAX_DISPLAY_W 2560
# define MAX_DISPLAY_H 1440
# define MIN_DISPLAY_W 500
# define MIN_DISPLAY_H 300

# define RGB(r, g, b) ((r) << 16 | (g) << 8 | (b))

# define MVSPEED 0.1
# define RTSPEED 0.05

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct	s_fc
{
	float	rayx0;
	float	rayy0;
	float	rayx1;
	float	rayy1;
	int		p;
	float	posz;
	float	rdist;
	float	stepx;
	float	stepy;
	float	floorx;
	float	floory;
	int		cellx;
	int		celly;
	int		tx;
	int		ty;
	int		floortex;
	int		ceilingtex;
	int		color;
}				t_fc;

typedef struct	s_spr
{
	int		*num;
	float	*dist;
	float	sprx;
	float	spry;
	float	distce;
	float	trx;
	float	trry;
	int		scrnx;
	int		mscrnx;
	int		height;
	int		dstry;
	int		dendy;
	int		width;
	int		dstrx;
	int		dendx;
	int		tex;
	int		texy;
	int		color;
	int		d;
}				t_spr;

typedef	struct	s_bmp
{
	int			i;
	int			j;
	int			tmp;
	int			fd;
}				t_bmp;

typedef struct	s_rct
{
	float		cam;
	float		raydirx;
	float		raydiry;
	int			mpx;
	int			mpy;
	float		sdistx;
	float		sdisty;
	float		ddistx;
	float		ddisty;
	float		pwalld;
	float		step;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lheight;
	int			dstart;
	int			dend;
	int			tnum;
	float		xwall;
	int			texx;
	float		tpos;
	int			texy;
}				t_rct;

typedef	struct	s_g
{
	int			heightm;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f[3];
	int			c[3];
	char		*k;
	long long	winw;
	long long	winh;
	char		*str;
	int			count;
	t_sprite	*sprite;
	int			numspr;
	t_fc		fc;
	t_spr		spr;
	t_bmp		bmp;
	t_rct		rct;
	char		**map;
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		planex;
	float		planey;
	void		*mlx;
	void		*win;
	int			key_a;
	int			key_left;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_right;
	int			key_esc;
	t_img		img;
	int			**buf;
	float		*zbuffer;
	int			**texture;
	int			save;
	int			i;
	int			j;
	int			x;
	int			n;
}				t_g;

typedef struct	s_pair
{
	float		first;
	int			second;
}				t_pair;

void			ft_navigation(t_g *g, char c);
void			ft_player_pos(t_g *g);
void			ft_sprites(t_g *g);
void			make_map(t_list **head, t_g *g);
void			parsing_map(char *av, t_g *g);
void			parsing_flags(char *av, t_g *g);
void			parsing_flags_nd(char *line, t_g *g);
void			parsing_flags_rd(char *av, t_g *g);
void			parse_arr(t_g *st, char c);
void			sort_num(t_pair *num, int count);
void			sortspr(int *num, float *dist, int count);
void			draw(t_g *g);
int				start_app(t_g *g);
void			keys(t_g *g);
int				press_k(int key, t_g *g);
int				reset_k(int key, t_g *g);
void			load_texture(t_g *g);
void			ft_load_image(t_g *g, int *texture, char *path, t_img *img);
void			walls(t_g *g);
void			floor_ceiling(t_g *g);
void			ft_window(t_g g);
int				ft_free(t_g *g);
void			struct_init(t_g *g);
void			ft_error(int x, t_g *g);
void			ft_parse_error(t_g *g);
void			ft_read_spr(t_g *g);
void			correct_wh(t_g *g);
void			game_loop(t_g *g, char *str);
void			ft_for_malloc(t_g *g);
int				save_bmp(t_g *g);
void			check_close_map(int x, int y, t_g *g, int height);
void			check_close(t_g *g);
void			ft_wall_casting(t_g *g);
int				xpm_correct(char *str, t_g *g, char *nstr, int fl);
char			*ft_convert(char *line, t_g *g, int j);
void			key_l(t_g *g);
int				ft_free_exit(t_g *g);
void			key_da(t_g *g);
void			ft_putstr_err(char *str);

#endif
