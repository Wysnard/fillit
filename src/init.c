/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:09:56 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/21 13:00:58 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_initmap(unsigned short **map, size_t max)
{
	size_t			i;

	i = 0;
	if (max == 0)
		return ;
	while (i < max)
		(*map)[i++] = 0;
	return ;
}

unsigned short	ft_gettetinline(unsigned char tet)
{
	unsigned short tet_inline;

	tet_inline = (unsigned short)tet;
	if (ft_issqrtet(tet))
		tet_inline = TETSQR;
	else if (ft_isdwbtet(tet)) 
		tet_inline = TETDWB;
	else if (ft_isupbtet(tet)) 
		tet_inline = TETUPB;
	else if (ft_isdwrtet(tet)) 
		tet_inline <<= 10;
	else if (ft_isuprtet(tet)) 
		tet_inline <<= 10;
	return (tet_inline);
}
