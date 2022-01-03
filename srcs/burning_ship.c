/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:28:35 by lsidan            #+#    #+#             */
/*   Updated: 2022/01/03 16:28:22 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fractol.h"

void	burning_ship_init(t_vars *d)
{
	d->zoom = WIDTH / 4;
	d->depth_max = 128;
	d->x1 = -2;
	d->y1 = -2;
	d->fract_ft = &burning_ship;
}

int	burning_ship(int x, int y, t_vars *d)
{
	int	iter;

	iter = 0;
	d->re = x / d->zoom + d->x1;
	d->im = y / d->zoom + d->y1;
	d->i = 0;
	d->j = 0;
	d->ii = d->i * d->i;
	d->jj = d->j * d->j;
	while (d->ii + d->jj <= 4 && iter < d->depth_max)
	{
		d->ii = d->i * d->i;
		d->jj = d->j * d->j;
		d->j = fabs(2.0 * d->i * d->j) + d->im;
		d->i = d->ii - d->jj + d->re;
		iter++;
	}
	return (iter);
}
