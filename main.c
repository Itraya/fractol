/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:24:53 by mlagrang          #+#    #+#             */
/*   Updated: 2021/12/02 13:26:33 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

#define depth_max 1000
#define HEIGHT 640
#define WIDTH 640

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
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		zx;
	int		zy;
	double	lzx;
	double	lzy;
	double	zoom;
	unsigned int	color;
	t_data	*im;
}		t_vars;

int	close(t_vars	*var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(EXIT_SUCCESS);
}

t_cpl	init_cpl(int x, int y , double zoom)
{
	t_cpl	c;

	c.re = 2.0 * 2.0 / zoom * (x - WIDTH / 2.0) / WIDTH;
	c.im = 2.0 * 2.0 / zoom * (y - HEIGHT / 2.0) / WIDTH;
	return (c);
}

int	mandelbrot_p(int x, int y, t_vars *var)
{
	t_cpl	complex;
	t_cpl	nb;
	int		depth;
	double	rec;
	double	imc;

	complex = init_cpl(x + ((var->zx - WIDTH / 2)),
			y + ((var->zy - HEIGHT / 2)), var->zoom);
	depth = 0;
	nb.re = 0;
	nb.im = 0;
	rec = 0;
	imc = 0;
	while (rec + imc <= 4 && depth < depth_max)
	{
		nb.im = 2 * nb.re * nb.im + complex.im;
		nb.re = rec - imc + complex.re;
		rec = nb.re * nb.re;
		imc = nb.im * nb.im;
		depth++;
	}
	return (depth);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mandelbrot_d(t_vars *v)
{
	int	x;
	int	y;
	int	pixel;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(v->im, x, y, v->color * mandelbrot_p(x, y, v));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->im->img, 0, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 'c')
		vars->color *= 0x0A0A0A;
	if (keycode == 'r')
	{
		vars->zoom = 1;
		vars->zx = WIDTH / 2;
		vars->zy = HEIGHT / 2;
		vars->lzx = 0;
		vars->lzy = 0;
	}
	mlx_clear_window(vars->mlx,vars->win);
	mandelbrot_d(vars);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("button = %d\n", button);
	if (button == 1)
		printf("%d	%d\n", vars->x, vars->y);
	if (button == 4)
	{
		if (vars->zx != WIDTH/2 || vars->zy != HEIGHT/2)
		{
			vars->lzx = vars->zx + vars->lzx / vars->zoom;
			vars->lzy = vars->zy + vars->lzx / vars->zoom;
		}
		dprintf(1, "%d	%d	%d	%d	%f", vars->zx, WIDTH/2, vars->zy, HEIGHT/2, vars->zoom);
		vars->zx = (vars->lzx + x) / vars->zoom;
		vars->zy = (vars->lzy + y) / vars->zoom;
		vars->zoom = vars->zoom * 1.3;
	}
	mlx_clear_window(vars->mlx,vars->win);
	mandelbrot_d(vars);
}

int	mouse_pos(int x, int y, t_vars *vars)
{
	//vars->x = x;
	//vars->y = y;
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	float	i;

	(void)(ac);
	(void)(av);
	vars.x = 0;
	vars.y = 0;
	vars.zoom = 1;
	vars.zx = WIDTH / 2;
	vars.zy = HEIGHT / 2;
	vars.lzx = 0;
	vars.lzy = 0;
	vars.im = &img;
	vars.color = 0x0000FF;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "UwU");
	vars.im->img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.im->addr = mlx_get_data_addr(vars.im->img, &vars.im->bits_per_pixel,
			&vars.im->line_length, &vars.im->endian);
	mandelbrot_d(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_pos, &vars);
	mlx_hook(vars.win, 17, 1L << 2, close, &vars);
	mlx_loop(vars.mlx);
}
