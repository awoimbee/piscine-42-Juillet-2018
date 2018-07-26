/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:37:24 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/25 15:43:51 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree		*nw_tree;

	if ((nw_tree = (t_btree*)malloc(sizeof(*nw_tree))) == 0)
		return (0);
	nw_tree->item = item;
	nw_tree->left = 0;
	nw_tree->right = 0;
	return (nw_tree);
}
