/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piledel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:58:57 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:59:22 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_piledel(t_pile *pile)
{
	t_list	*list;
	void	*cont;

	cont = NULL;
	if (pile == NULL)
		exit(EXIT_FAILURE);
	if (pile->first != NULL)
	{
		list = pile->first;
		cont = list->content;
		pile->first = list->next;
		free(list);
	}
	return (cont);
}
