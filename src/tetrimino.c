/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:52:56 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 17:33:29 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_placetetris(unsigned short *map,
		unsigned char at, t_etris tetris, unsigned char tetnum)
{
	unsigned	short	tet;

	tet = tetris.tetris[tetnum];
	while (tetris.h[tetnum])
	{
		map[at / 16] |= (tet & 0xF000) >> (at & 15);
		tet = tet << 4;
		tetris.h[tetnum] -= 1;
		at += 16;
	}
}
