/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilepushadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:59:41 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 17:00:11 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pilepushadd(t_pile *pile, void *info, size_t content_size)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = NULL;
	if (!(new = ft_lstnew(info, content_size)) || !pile)
		exit(EXIT_FAILURE);
	ft_lstpushadd(&pile->first, new);
}
