/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:59:55 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/25 16:59:57 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "unistd.h"

void	*btree_search_item(t_btree *root, void *data_ref,
						int (*cmpf)(void *, void *))
{
	void	*res;

	if (!root || !cmpf)
		return (0);
	if (root->left)
		if ((res = btree_search_item(root->left, data_ref, cmpf)))
			return (res);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (root->right)
		if ((res = btree_search_item(root->right, data_ref, cmpf)))
			return (res);
	return (NULL);
}
