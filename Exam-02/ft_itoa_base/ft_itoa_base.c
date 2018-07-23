/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 20:57:23 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 21:24:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*f_strrev(char *str)
{
	char	*start;
	char	*end;
	char	buff;

	start = str;
	end = str;
	while (*(end + 1))
		++end;
	while (start < end)
	{
		buff = *start;
		*start = *end;
		*end = buff;
		start++;
		end--;
	}
	return (str);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str_base;
	char	*result;
	int		i;
	int		sign;

	sign = (value < 0) ? -1 : 1;
	str_base = "0123456789ABCDEF";
	result = malloc(((value / base) * sign + 2) * sizeof(char));
	i = 0;
	while (value != 0)
	{
		result[i++] = str_base[(value % base) * sign];
		value /= base;
	}
	if (sign == -1)
		result[i++] = '-';
	result[i++] = '\0';
	return (f_strrev(result));
}
