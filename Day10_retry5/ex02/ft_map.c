/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:20:28 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/16 13:20:31 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*result;
	int		i;

	result = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		result[i] = (*f)(tab[i]);
		++i;
	}
	return (result);
}
