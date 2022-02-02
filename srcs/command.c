/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:33:47 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/04 10:38:04 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fractol.h"

void	ft_zoom(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	x = WIDTH / 2;
	y = HEIGHT / 2;
	if (keycode == 36 && (vars->fun != 2 || vars->pause_julia == 1))
	{
		vars->x1 = (x / vars->zoom + vars->x1) - (x / (vars->zoom * 1.3));
		vars->y1 = (y / vars->zoom + vars->y1) - (y / (vars->zoom * 1.3));
		vars->zoom = vars->zoom * 1.3;
		vars->depth_max += 5;
	}
	else if (keycode == 51 && (vars->fun != 2 || vars->pause_julia == 1))
	{
		vars->x1 = (x / vars->zoom + vars->x1) - (x / (vars->zoom / 1.3));
		vars->y1 = (y / vars->zoom + vars->y1) - (y / (vars->zoom / 1.3));
		vars->zoom = vars->zoom / 1.3;
		vars->depth_max -= 5;
	}
}

void	ft_move(int keycode, t_vars *vars)
{
	if (keycode == 49 && vars->fun == 2)
	{
		if (vars->pause_julia == 1)
			init_all(vars);
		vars->pause_julia = !vars->pause_julia;
	}
	else if (keycode == 126)
		vars->y1 = vars->y1 - 50 / vars->zoom;
	else if (keycode == 125)
		vars->y1 = vars->y1 + 50 / vars->zoom;
	else if (keycode == 124)
		vars->x1 = vars->x1 + 50 / vars->zoom;
	else if (keycode == 123)
		vars->x1 = vars->x1 - 50 / vars->zoom;
	else if (keycode == 36 || keycode == 51)
		ft_zoom(keycode, vars);
}

void	get_pal_keycode(int keycode, t_vars *vars)
{
	if (keycode >= 18 && keycode <= 21)
		vars->pal = &get_pal()[keycode - 18];
	if (keycode == 23)
		vars->pal = &get_pal()[4];
	if (keycode == 22)
		vars->pal = &get_pal()[5];
	if (keycode == 26)
		vars->pal = &get_pal()[6];
	if (keycode == 28)
		vars->pal = &get_pal()[7];
}
