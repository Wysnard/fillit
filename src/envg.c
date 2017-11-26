/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 22:55:14 by schmurz           #+#    #+#             */
/*   Updated: 2017/11/26 23:22:51 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	ft_get1s(unsigned short byte)
{
	int i;
	int	one;

	i = 0;
	one = 0;
	while (i < 16)
	{
		byte >>= 1;
		if (byte & 1)
			one++;
		i++;
	}
	return (one);
}

unsigned char ft_co0inline(unsigned short line, size_t min)
{
	unsigned char at;
	unsigned char zer;
	unsigned char	maxzer;

	at = 0;
	zer = 0;
	maxzer = 0;
	while (at < min)
	{
		if (ft_getbitat(line, at) == 0)
			zer++;
		else
		{
			maxzer = (maxzer > zer) ? maxzer : zer;
			zer = 0;
		}
		at++;
	}
	maxzer = (maxzer > zer) ? maxzer : zer;
	return (maxzer);
}

unsigned char ft_env(unsigned short line, size_t min, unsigned short tet)
{
	return (ft_co0inline(line, min) < ft_get1s(tet & 0xF000));
}
