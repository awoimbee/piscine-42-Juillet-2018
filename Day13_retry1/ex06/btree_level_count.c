/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:54:37 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/25 17:54:39 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int		left;
	int		right;

	if (!root)
		return (0);
	if (!(left = 0) && root->left)
		left = btree_level_count(root->left);
	if (!(right = 0) && root->right)
		right = btree_level_count(root->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
