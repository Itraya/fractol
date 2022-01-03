/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:03:50 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/03 16:12:43 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fractol.h"

t_pal	*get_pal(void)
{
	static t_pal	tab[4];

	// tab[0] = \
	// 	(t_pal){15, {0x2a4858, 0x255566, 0x1c6373, \
	// 					0x0b717e, 0x007f86, 0x008d8c, \
	// 					0x009c8f, 0x23aa8f, 0x3fb78d, \
	// 					0x5bc489, 0x77d183, 0x95dd7d, \
	// 					0xb5e877, 0xd7f171, 0xfafa6e}};
	// tab[1] = \
	// 	(t_pal){5, {0x000764, 0x206BCB, 0xFFFFFF, \
	// 					0xFFAA00, 0x000200}};
	// tab[2] = \
	// 	(t_pal){5, {0xF8F8FF, 0xCAC9CD, 0x9B9A9C, \
	// 					0x6D6A6A, 0x3E3B39}};
	// tab[3] = \
	// 	(t_pal){7, {0xFF0000, 0xFFFF00, 0x00FF00, \
	// 					0x00FFFF, 0x0000FF, 0xFF00FF, \
	// 					0xFF0000}};
	tab[0] = \
		(t_pal){15, {0xd5b7a7, 0xdaaa99, 0xe39c8c, \
						0xf48e81, 0xff8079, 0xff7273, \
						0xff6370, 0xdc5570, 0xc04872, \
						0xa43b76, 0x882e7c, 0x6a2282, \
						0x4a1788, 0x280e8e, 0x050591}};
	tab[1] = \
		(t_pal){5, {0xfff89b, 0xdf9434, 0x000000, \
						0x0055ff, 0xfffdff}};
	tab[2] = \
		(t_pal){5, {0x070700, 0x353632, 0x646563, \
						0x929595, 0xc1c4c6}};
	tab[3] = \
		(t_pal){7, {0x00FFFF, 0x0000FF, 0xFF00FF, \
						0xFF0000, 0xFFFF00, 0x00FF00, \
						0x00FFFF}};
	return (tab);
}

int	init_all(t_vars *vars)
{
	vars->x1 = -2;
	vars->y1 = -2;
	vars->zoom = WIDTH / 4;
	vars->zx = WIDTH / 2;
	vars->zy = HEIGHT / 2;
	vars->lzx = 0;
	vars->lzy = 0;
	vars->color = 0x0FF088;
	vars->depth_max = 50;
	vars->pal = get_pal();
	vars->affx = NULL;
	vars->affy = NULL;
	vars->affx = ft_itoa(WIDTH * 0.3, vars->affx);
	vars->affy = ft_itoa(WIDTH * 0.461, vars->affy);
	return (0);
}
