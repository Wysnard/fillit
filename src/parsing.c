/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:31:29 by vlay              #+#    #+#             */
/*   Updated: 2017/11/25 20:31:31 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_cttetris(char *buf)
{
	size_t	i;
	size_t	n;
	size_t	pt;

	i = 0;
	n = 0;
	pt = 0;
	if (buf[i] != '#' && buf[i] != '.')
		return (0);
	while (buf[i])
	{
		if ((i == 4 || i == 9 || i == 14 || i == 19) && buf[i] != '\n')
			return (0);
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			n++;
		if (buf[i] == '.')
			pt++;
		i++;
	}
	if (pt != 12 || buf[i - 1] != '\n')
		return (0);
	return (n);
}
