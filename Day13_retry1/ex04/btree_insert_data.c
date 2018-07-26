/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:59:31 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/25 15:59:33 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
						int (*cmpf)(void *, void *))
{
	if (root == 0 || item == 0 || cmpf == 0)
		return ;
	if (*root == 0)
		*root = btree_create_node(item);
	else
	{
		if (cmpf(item, (*root)->item) < 0)
		{
			if ((*root)->left)
				btree_insert_data(&(*root)->left, item, cmpf);
			else
				(*root)->left = btree_create_node(item);
		}
		else
		{
			if ((*root)->right)
				btree_insert_data(&(*root)->right, item, cmpf);
			else
				(*root)->right = btree_create_node(item);
		}
	}
}
