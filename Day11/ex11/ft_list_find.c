/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:05:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 19:05:25 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	if ((list_ptr = begin_list) == 0)
		return (0);
	while (list_ptr->next)
	{
		if (((*cmp)(list_ptr->data, data_ref)) == 0)
			return (list_ptr);
		list_ptr = list_ptr->next;
	}
	return (0);
}
