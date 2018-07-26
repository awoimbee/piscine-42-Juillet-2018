/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:20:55 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/25 18:20:57 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		g_lvl;

int		do_it(t_btree *root, int lvl, int f, void (*applyf)())
{
	int		i;

	if (lvl)
	{
		i = 0;
		if (root->left)
			i += do_it(root->left, lvl - 1, f, applyf);
		if (i > 0)
			f = 0;
		if (root->right)
			i += do_it(root->right, lvl - 1, f, applyf);
		return (i);
	}
	applyf(root->item, g_lvl, f);
	return (1);
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		i;

	if (root == 0)
		return ;
	i = -1;
	while (++i != -1)
	{
		g_lvl = i;
		if (!do_it(root, i, 1, applyf))
			return ;
	}
}
