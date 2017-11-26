/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:32:22 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 14:59:09 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

size_t	ft_read(int fd, t_etris *t)
{
	int		r;
	size_t	m;
	char	b[BUFF_SIZE + 1];

	m = 0;
	b[0] = '\0';
	while ((r = read(fd, b, BUFF_SIZE)))
	{
		b[r] = '\0';
		if (m > 26 || !(t->tetris[m] = std(rb(b))) || ctt(b) != 4 ||
		!(ft_hl(t->tetris[m], &t->h[m], &t->l[m])) || (t->h[m] + t->l[m] != 5 &&
		t->h[m] + t->l[m] != 4))
			return (0);
		m++;
	}
	if (m == 0 || ft_strlen(b) != 20)
		return (t->min = 0);
	t->tetris[m] = 0;
	t->h[m] = 0;
	t->l[m] = 0;
	ft_bzero(t->at, 27);
	t->nb = (unsigned char)m;
	return (t->min = (m < 2) ? 2 : ft_sqr(m * 4));
}
