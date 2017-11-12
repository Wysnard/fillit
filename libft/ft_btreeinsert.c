/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:21:59 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:22:35 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeinsert(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		*root = ft_btreecreate(item);
	if ((*cmpf)((*root)->content, item) >= 0 && (*root)->left != NULL)
		ft_btreeinsert(&(*root)->left, item, cmpf);
	if ((*cmpf)((*root)->content, item) < 0 && (*root)->right != NULL)
		ft_btreeinsert(&(*root)->right, item, cmpf);
	if ((*cmpf)((*root)->content, item) >= 0 && (*root)->left == NULL)
		(*root)->left = ft_btreecreate(item);
	if ((*cmpf)((*root)->content, item) < 0 && (*root)->right == NULL)
		(*root)->right = ft_btreecreate(item);
}
