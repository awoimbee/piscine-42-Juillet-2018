/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 21:28:37 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 21:51:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base);

void	ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	temp;

	start = str;
	end = str;
	while (*end)
		++end;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}

char	*f_u(value)
{
	char	*pos_res;

	pos_res = ft_itoa_base(-value, 10);
	--pos_res;
	*pos_res = '-';	
	return (pos_res);
}

char	*ft_itoa_base(int value, int base)
{
	char	*base_char;
	char	*result;
	int		i;

	result = malloc(33 * sizeof(int));
	++result;
	if (base == 10 && value < 0)
		return (f_u(value));
	if (base < 2 || base > 16)
		return ("0");
	base_char = "0123456789ABCDEF";
	i = 0;
	while (value > 0)
	{
		result[i] = base_char[value % base];
		value /= base;
		++i;
	}
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}
