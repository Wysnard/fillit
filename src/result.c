/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:52:16 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/20 19:43:48 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_initresulttab(unsigned char min)
{
	char	**tab;
	size_t	i;

	if (!(tab = (char **)malloc(sizeof(char *) * min + 1)))
		return (NULL);
	i = 0;
	while (i < min)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * min + 2)))
			return (NULL);
		ft_memset(tab[i], '.', min);
		tab[i][min] = '\n';
		tab[i][min + 1] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_fillresulttab(char **tab, unsigned char at, unsigned char tetnum, t_etris *tetris)
{
	unsigned	char	i;
	unsigned	char	j;
	unsigned short	tet_inline;

	i = 0;
	tet_inline = tetris->tetris[tetnum];
	while (i < tetris->h[tetnum])
	{
		j = 0;
		while (j < 4)
		{
			if (tet_inline & (1 << 15))
				tab[(at / 16)+ i][(at % 16) + j] = tetnum + 'A';
			tet_inline <<= 1;
			j++;
		}
		i++;
	}
}
