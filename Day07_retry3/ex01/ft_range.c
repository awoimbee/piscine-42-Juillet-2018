/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:26:25 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/10 12:26:27 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
		return (0);
	tab = (int*)malloc((max - min) * sizeof(int));
	i = min;
	while (i < max)
	{
		tab[i - min] = i;
		++i;
	}
	return (tab);
}
