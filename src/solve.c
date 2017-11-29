/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:53:45 by vlay              #+#    #+#             */
/*   Updated: 2017/11/29 12:16:41 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		tetline = (0xF000 & (tetris.tet[tetnum] << (4 * i))) >> (at & 15);
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

int	ft_solve(t_etris *t, unsigned short *p, size_t m,
	unsigned char n)
{
	size_t			i;
	unsigned short	save[16];

	if (t->tet[n] == 0)
		return (1);
	if ((m * m - ft_getdcnum(p, m) - 4 * n)
			< (4 * (ft_strlen((const char*)t->h) - n)))
		return (0);
	i = 0;
	ft_uscpy(save, p, m);
	while (((i / 16) + t->h[n] - 1) < m)
	{
		if (((i + t->l[n] - 1) & 15) >= m || ft_env(p[i / 16], m, t->tet[n]))
			i = i + 16 - (i & 15);
		if (((i / 16) + t->h[n] - 1) < m && ft_fit_in(p, i, *t, n))
		{
			t->at[n] = i;
			if (ft_solve(t, p, m, n + 1))
				return (1);
			else
				ft_uscpy(p, save, m);
		}
		i = ((i - m) & 15) ? (i + 1) : (i);
	}
	return (0);
}
