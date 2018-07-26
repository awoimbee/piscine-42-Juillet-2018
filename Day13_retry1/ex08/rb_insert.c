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

#include "ft_btree_rb.h"

void	rb_insert(struct s_rb_node **root, void *data,
				int (*cmpf)(void *, void *))
{
	if (root == 0 || data == 0 || cmpf == 0)
		return ;
	if (*root == 0)
		*root = btree_create_node(data);
	else
	{
		if (cmpf(data, (*root)->data) < 0)
		{
			if ((*root)->left)
				rb_insert(&(*root)->left, data, cmpf);
			else
				(*root)->left = btree_create_node(data);
		}
		else
		{
			if ((*root)->right)
				rb_insert(&(*root)->right, data, cmpf);
			else
				(*root)->right = btree_create_node(data);
		}
	}
}
