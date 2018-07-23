/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:37:38 by exam              #+#    #+#             */
/*   Updated: 2018/07/06 20:48:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*skp_lead_white(char *str)
{
	while (*str == ' '
			|| *str == '\n'
			|| *str == '\t'
			|| *str == '\v'
			|| *str == '\f'
			|| *str == '\r')
	{
		++str;
	}
	return (str);
}

int		char_to_int(char *str_start, char *str_end, int coeff)
{
	int result;

	result = 0;
	while (str_start < str_end)
	{
		write(1, &str_start, 1);
		result += (*str_start - '0') * coeff;
		coeff /= 10;
		++str_start;
	}
	return (result);
}

int		ft_atoi(const char *str)
{
	int		coeff;
	char	*str2;
	char	*str_start;

	coeff = 1;
	str2 = skp_lead_white(str);
	if (*str2 == '+')
		++str2;
	else if (*str2 == '-')
	{
		++str2;
		coeff *= -1;
	}
	str_start = str2;
	while ('0' <= *str2 && *str2 <= '9')
	{
		++str2;
		coeff *= 10;
	}
	coeff /= 10;
	write(1, str_start, 2);
	return (char_to_int(str_start, str2, coeff));
}
