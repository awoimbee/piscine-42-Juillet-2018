/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:48:03 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 12:48:06 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;

	if (begin_list == 0)
		return (0);
	i = 1;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}
