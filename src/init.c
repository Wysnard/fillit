/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:09:56 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/20 17:17:45 by vlay             ###   ########.fr       */
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

unsigned short	ft_gettetinline(unsigned char tet, char *h, char *l)
{
	unsigned short tet_inline;

	tet_inline = (unsigned short)tet;
	if (ft_issqrtet(tet) && ft_hlassign(h, l, 2, 2))
		tet_inline = TETSQR;
	else if (ft_isdwbtet(tet) && ft_hlassign(h, l, 1, 4))
		tet_inline = TETDWB;
	else if (ft_isupbtet(tet) && ft_hlassign(h, l, 4, 1))
		tet_inline = TETUPB;
	else if (ft_isdwrtet(tet) && ft_hlassign(h, l, 2, 3))
		tet_inline <<= 10;
	else if (ft_isuprtet(tet) && ft_hlassign(h, l, 3, 2))
		tet_inline <<= 10;
	return (tet_inline);
}
