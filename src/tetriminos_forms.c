/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_forms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:17:06 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/20 18:49:44 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_isdwrtet(unsigned char tet)
{
	return (tet >> 6 == 0);
}

int	ft_isuprtet(unsigned char tet)
{
	return (tet >> 6 == 1);
}

int	ft_issqrtet(unsigned char tet)
{
	return (tet >> 6 == 3);
}

int	ft_isdwbtet(unsigned char tet)
{
	return (tet >> 5 == 4);
}

int	ft_isupbtet(unsigned char tet)
{
	return (tet >> 5 == 5);
}

int	ft_hlassign(unsigned char *h, unsigned char *l, char val_h, char val_l)
{
	*h = val_h;
	*l = val_l;
	return (1);
}

unsigned short ft_getlinemask(char l)
{
	unsigned short	mask;
	mask = 0;
	while (l-- > -1)
		mask = mask + (1 << (15 - l));
	return (mask);
}
