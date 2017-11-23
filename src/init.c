/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:09:56 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/23 20:34:42 by dsaadia          ###   ########.fr       */
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
	if (ft_issqrtet(tet) || ft_isdwbtet(tet) || ft_isupbtet(tet))
		return (TETSQR);
	else if (ft_isdwrtet(tet) || ft_isuprtet(tet))
		return (tet_inline << 10);
	return (0);
}
