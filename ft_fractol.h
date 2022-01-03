/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:27:50 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/03 15:52:24 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include "mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# define HEIGHT 900
# define WIDTH 900

typedef unsigned char	t_char;

typedef struct s_pal
{
	t_char		count;
	int			colors[16];
}					t_pal;

typedef struct s_rgba
{
	t_char	r;
	t_char	g;
	t_char	b;
	t_char	a;
}	t_rgba;

typedef union s_color {
	t_rgba	rgba;
	int		value;
}	t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_cpl
{
	double	im;
	double	re;
}		t_cpl;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	double			re;
	double			im;
	int				depth_max;
	double			x1;
	double			y1;
	double			i;
	double			j;
	double			ii;
	double			jj;
	int				zx;
	int				zy;
	double			lzx;
	double			lzy;
	double			zoom;
	unsigned int	color;
	int				fun;
	int				pause_julia;
	void			*fract_ft;
	char			*affx;
	char			*affy;
	t_data			*ima;
	t_pal			*pal;
}		t_vars;

void	ft_color(t_vars *v, int x, int y, int iter);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_vars *v, int (*f)(int, int, t_vars *));
void	ft_choix(t_vars *v);
int		init_all(t_vars *vars);
void	burning_ship_init(t_vars *d);
int		burning_ship(int x, int y, t_vars *d);
void	julia_init(t_vars *d);
int		julia(int x, int y, t_vars *d);
void	mandel_init(t_vars	*d);
int		mandelbrot_p(int x, int y, t_vars *var);
int		check_av(char **a, t_vars *v);
void	ft_move(int keycode, t_vars *vars);
char	*ft_itoa(int n, char *a);
int		ft_exit(t_vars *vars);
void	ft_draw(t_vars *v, int (*f)(int, int, t_vars *));
t_pal	*get_pal(void);

#endif