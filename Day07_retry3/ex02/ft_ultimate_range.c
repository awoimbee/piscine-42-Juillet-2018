/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:45:54 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/10 12:46:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tab = (int*)malloc((max - min) * sizeof(int));
	i = min;
	while (i < max)
	{
		tab[i - min] = i;
		++i;
	}
	*range = tab;
	return (max - min);
}
