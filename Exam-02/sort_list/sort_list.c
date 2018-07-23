/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:28:10 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 19:43:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		i;
	int		buff;

	if (!lst || !cmp || !(lst->next))
		return (lst);
	i = -1;
	while (lst[++i].next)
	{
		if ((*cmp)(lst[i].data, lst[i + 1].data) == 0)
		{
			buff = lst[i].data;
			lst[i].data = lst[i + 1].data;
			lst[i + 1].data = buff;
			i = -1;
		}
	}
	return (lst);
}
