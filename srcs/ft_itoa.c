/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:08:28 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/03 15:52:08 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fractol.h"

char	*remp(char *tab, int nb, int l, int s)
{
	long int	n;

	n = nb;
	if (n < 0)
		n = n * -1;
	while (l-- > s)
	{
		tab[l] = (n % 10) + '0';
		n = n / 10;
	}
	if (l == 0)
		tab[0] = '-';
	return (tab);
}

char	*ft_itoa(int n, char *a)
{
	int				l;
	int				s;
	long int		nb;

	free(a);
	l = 0;
	s = 0;
	nb = n;
	if (n < 0)
		nb = nb * -1 + s++;
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	if (n == 0)
		l = 1;
	a = malloc(l + s + 1);
	if (!a)
		return (0);
	a[l + s] = '\0';
	return (remp(a, n, l + s, s));
}
