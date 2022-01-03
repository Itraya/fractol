/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:02:03 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/03 15:19:51 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw(t_vars *v, int (*f)(int, int, t_vars *))
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_color(v, x, y, f(x, y, v));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->ima->img, 0, 0);
}

void	ft_choix(t_vars *v)
{
	if (v->fun == 1)
		mandel_init(v);
	else if (v->fun == 2)
		julia_init(v);
	else if (v->fun == 3)
		burning_ship_init(v);
	ft_draw(v, v->fract_ft);
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (b[i] - a[i]);
}

int	check_av(char **a, t_vars *v)
{
	if (!ft_strcmp(a[1], "mandelbrot"))
	{
		v->fun = 1;
		v->fract_ft = &mandelbrot_p;
		return (1);
	}
	if (!ft_strcmp(a[1], "julia"))
	{
		v->fun = 2;
		v->fract_ft = &julia;
		return (1);
	}
	if (!ft_strcmp(a[1], "burning_ship"))
	{
		v->fun = 3;
		v->fract_ft = &mandelbrot_p;
		return (1);
	}
	return (0);
}
