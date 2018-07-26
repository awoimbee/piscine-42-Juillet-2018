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

void rb_remove(struct s_rb_node **root, void *data,
			int (*cmpf)(void *, void *), void (*freef)(void *))
{
	if ((*root)->left)
		rb_remove(&(*root)->left, data, cmpf, freef);
	if ((*root)->right)
		rb_remove(&(*root)->right, data, cmpf, freef);
	freef(*root);
	(void)data;
	(void)cmpf;
}
