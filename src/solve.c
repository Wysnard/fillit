/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:53:45 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 22:05:21 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_compare(unsigned short *map,
		size_t at, t_etris tetris, unsigned char tetnum)
{
	unsigned char	i;
	unsigned short	linemask;
	unsigned short	tetline;

	i = 0;
	linemask = ft_getlinemask(tetris.l[tetnum]);
	while (i < tetris.h[tetnum])
	{
		tetline = (0xF000 & (tetris.tetris[tetnum] << (4 * i))) >> (at & 15);
		if ((map[at / 16] ^ tetline) != (map[at / 16] | tetline))
			return (0);
		i++;
		at += 16;
	}
	return (1);
}

int	ft_fit_in(unsigned short *map, size_t at,
		t_etris tetris, unsigned char tetnum)
{
	if (!ft_compare(map, at, tetris, tetnum))
		return (0);
	ft_placetetris(map, at, tetris, tetnum);
	return (1);
}

int	ft_solve(t_etris *t, unsigned short *map, size_t min,
	unsigned char tn)
{
	size_t			i;
	unsigned short	save[16];

	if (t->tetris[tn] == 0)
		return (1);
	if ((min * min - ft_getdcnum(map, min) - 4 * tn)
			< (4 * (ft_strlen((const char*)t->h) - tn)))
		return (0);
	i = 0;
	ft_uscpy(save, map, min);
	while (((i / 16) + t->h[tn] - 1) < min)
	{
		if (((i + t->l[tn] - 1) & 15) >= min)
			i = i + 16 - (i & 15);
		if (((i / 16) + t->h[tn] - 1) < min && ft_fit_in(map, i, *t, tn))
		{
			t->at[tn] = i;
			if (ft_solve(t, map, min, tn + 1))
				return (1);
			else
				ft_uscpy(map, save, min);
		}
		i = ((i - min) & 15) ? (i + 1) : (i);
	}
	return (0);
}
