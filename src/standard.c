/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:31:52 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 14:53:32 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned	short	std(unsigned short c)
{
	if (c == 0)
		return (0);
	while (!(HEIGHTMASK & c))
		c = c << 4;
	while (!(LENGTHMASK & c))
		c = c << 1;
	return (c);
}

int					ft_hl(unsigned short c, unsigned char *h, unsigned char *l)
{
	size_t	i;
	size_t	j;

	i = 0;
	*h = 0;
	*l = 0;
	j = 0;
	while (i < 16)
	{
		if (HEIGHTMASK & (c << i))
			(*h) = j;
		i = 4 * j++;
	}
	i = 0;
	while (i < 4)
	{
		if (LENGTHMASK & (c << i))
			(*l) = i + 1;
		i += 1;
	}
	if (*h == 0 || *l == 0)
		return (0);
	return (1);
}
