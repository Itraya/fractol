/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:27:48 by lsidan            #+#    #+#             */
/*   Updated: 2022/01/03 15:07:29 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fractol.h"

void	julia_init(t_vars *d)
{
	d->depth_max = 50;
	d->zoom = WIDTH / 4;
	d->x1 = -2.0;
	d->y1 = -2.0;
	d->re = -0.8;
	d->im = 0.156;
	d->pause_julia = 0;
	d->fract_ft = &julia;
}

int	julia(int x, int y, t_vars *d)
{
	int		iter;

	iter = 0;
	d->i = x / d->zoom + d->x1;
	d->j = y / d->zoom + d->y1;
	d->ii = d->i * d->i;
	d->jj = d->j * d->j;
	while (d->ii + d->jj < 4 && iter < d->depth_max)
	{
		d->ii = d->i * d->i;
		d->jj = d->j * d->j;
		d->j = d->i * d->j;
		d->j = d->j + d->j + d->im;
		d->i = d->ii - d->jj + d->re;
		iter++;
	}
	return (iter);
}
