/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:04:41 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/03 15:30:51 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fractol.h"

void	mandel_init(t_vars	*d)
{
	d->depth_max = 50;
	d->zoom = WIDTH / 4;
	d->x1 = -2;
	d->y1 = -2;
	d->fract_ft = &mandelbrot_p;
}

int	mandelbrot_p(int x, int y, t_vars *var)
{
	int		depth;

	depth = 0;
	var->re = x / var->zoom + var->x1;
	var->im = y / var->zoom + var->y1;
	var->i = 0;
	var->j = 0;
	var->ii = var->i * var->i;
	var->jj = var->j * var->j;
	while (var->jj + var->ii <= 4 && depth < var->depth_max)
	{
		var->ii = var->i * var->i;
		var->jj = var->j * var->j;
		var->j = var->i * var->j;
		var->j = var->j + var->j + var->im;
		var->i = var->ii - var->jj + var->re;
		depth++;
	}
	return (depth);
}
