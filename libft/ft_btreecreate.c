/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreecreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:21:05 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:21:25 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreecreate(void *item)
{
	t_btree	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(*tmp));
	if (tmp)
	{
		tmp->content = item;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	return (tmp);
}
