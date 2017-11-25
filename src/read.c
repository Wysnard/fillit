/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:32:22 by vlay              #+#    #+#             */
/*   Updated: 2017/11/25 19:32:26 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

size_t	ft_read(int fd, t_etris *tetris)
{
	int	ret;
	size_t	min;
	char	buf[BUFF_SIZE + 1];

	min = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (min > 26 || !(tetris->tetris[min] = ft_standard(ft_registerbits(buf))) ||
					ft_cttetris(buf) != 4 ||
					!(ft_hl(tetris->tetris[min], &tetris->h[min], &tetris->l[min]))
					|| (tetris->h[min] + tetris->l[min] != 5 && tetris->h[min] + tetris->l[min] != 4))
			return (0);
		printf("h = %d | l = %d\n", tetris->h[min], tetris->l[min]);
		ft_print_bits(tetris->tetris[min], 15);
		ft_putchar('\n');
		min++;
	}
	tetris->tetris[min] = 0;
	tetris->h[min] = 0;
	tetris->l[min] = 0;
	ft_bzero(tetris->at, 27);
	tetris->nb = (unsigned char)min;
	if (min < 2)
		return (tetris->min = 2);
	return (tetris->min = ft_sqr(min * 4));
}
