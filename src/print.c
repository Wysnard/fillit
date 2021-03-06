/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:32:28 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 17:01:54 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_print_map(unsigned short *map, unsigned char min)
{
	size_t	i;

	i = 0;
	while (i < min)
	{
		ft_printnbits(map[i], 15, min);
		ft_putchar('\n');
		i += 1;
	}
}

size_t			ft_readtabbit(unsigned short *map, size_t at)
{
	return ((map[at / 16] & (1 << (at & 15))) ? 1 : 0);
}

void			ft_tabprintbit(unsigned short *map, size_t max)
{
	size_t	at;

	at = 0;
	(void)max;
	while (at < 104)
	{
		ft_putnbr(ft_readtabbit(map, at));
		at += 1;
	}
}

unsigned short	ft_getlinemask(char l)
{
	unsigned short	mask;

	mask = 0;
	while (l-- > -1)
		mask = mask + (1 << (15 - l));
	return (mask);
}
