/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:20:55 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/18 12:20:57 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

t_list		*ft_create_elem(void *data)
{
	t_list	*nw_elem;

	if ((nw_elem = malloc(sizeof(t_list))) == 0)
		return (NULL);
	nw_elem->data = data;
	nw_elem->next = NULL;
	return (nw_elem);
}
