/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:00:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 19:00:25 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	if ((list_ptr = begin_list) == 0)
		return ;
	while (list_ptr->next)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
