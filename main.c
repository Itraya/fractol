/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:24:53 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/02 10:41:37 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_close(t_vars	*var)
{
	mlx_destroy_window(var->mlx, var->win);
	free(var->affx);
	free(var->affy);
	exit(EXIT_SUCCESS);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4 && (vars->fun != 2 || vars->pause_julia == 1))
	{
		vars->x1 = (x / vars->zoom + vars->x1) - (x / (vars->zoom * 1.3));
		vars->y1 = (y / vars->zoom + vars->y1) - (y / (vars->zoom * 1.3));
		vars->zoom = vars->zoom * 1.3;
		vars->depth_max += 5;
	}
	if (button == 5 && (vars->fun != 2 || vars->pause_julia == 1)
		&& vars->depth_max > 10)
	{
		vars->x1 = (x / vars->zoom + vars->x1) - (x / (vars->zoom / 1.3));
		vars->y1 = (y / vars->zoom + vars->y1) - (y / (vars->zoom / 1.3));
		vars->zoom = vars->zoom / 1.3;
		vars->depth_max -= 5;
	}
	ft_draw(vars, vars->fract_ft);
	if (vars->fun == 2)
	{
		mlx_string_put(vars->mlx, vars->win, 0, 10, 0x000000, vars->affx);
		mlx_string_put(vars->mlx, vars->win, 0, 20, 0x000000, vars->affy);
	}
	return (0);
}

int	mouse_julia(int x, int y, t_vars *d)
{
	if (d->fun == 2 && d->pause_julia == 0)
	{
		d->re = 4 * ((double)x / WIDTH - 0.5);
		d->im = 4 * ((double)(WIDTH - y) / WIDTH - 0.5);
		ft_draw(d, &julia);
		d->affx = ft_itoa(x, d->affx);
		if (!d->affx)
			exit(EXIT_FAILURE);
		d->affy = ft_itoa(y, d->affy);
		if (!d->affy)
		{
			free(d->affx);
			exit(EXIT_FAILURE);
		}
		mlx_string_put(d->mlx, d->win, 0, 10, 0x000000, d->affx);
		mlx_string_put(d->mlx, d->win, 0, 20, 0x000000, d->affy);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close(vars);
	if (keycode == 15)
		init_all(vars);
	get_pal_keycode(keycode, vars);
	if (keycode == 11)
		vars->fun = 3;
	if (keycode == 38)
		vars->fun = 2;
	if (keycode == 46)
		vars->fun = 1;
	if ((keycode == 49 && vars->fun == 2) || (keycode >= 123 && keycode <= 126)
		|| keycode == 36 || keycode == 51)
		ft_move(keycode, vars);
	if (keycode == 11 || keycode == 38 || keycode == 46)
		ft_choix(vars);
	ft_draw(vars, vars->fract_ft);
	if (vars->fun == 2)
	{
		mlx_string_put(vars->mlx, vars->win, 0, 10, 0x000000, vars->affx);
		mlx_string_put(vars->mlx, vars->win, 0, 20, 0x000000, vars->affy);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;

	if (ac < 2)
		write(1, "Veuillez rentrer un parametre:\
\n-mandelbrot\n-julia\n-burning_ship\n", 64);
	if (!check_av(av, &vars) || ac < 2)
		return (0);
	vars.ima = &img;
	vars.finit = 0;
	vars.pal = get_pal();
	init_all(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "UwU");
	vars.ima->img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.ima->addr = mlx_get_data_addr(vars.ima->img, &vars.ima->bits_per_pixel,
			&vars.ima->line_length, &vars.ima->endian);
	ft_choix(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_julia, &vars);
	mlx_hook(vars.win, 17, 1L << 2, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
