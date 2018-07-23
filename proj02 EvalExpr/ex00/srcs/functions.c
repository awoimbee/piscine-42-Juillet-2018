/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:06:08 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/21 14:06:10 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void		ft_putnbr(int nb)
{
	long int	num;
	int			digit;
	long int	power_10;
	long int	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = nb2 * -1;
	}
	power_10 = 1;
	num = nb2;
	while (num > 9)
	{
		num /= 10;
		power_10 *= 10;
	}
	while (power_10 > 0)
	{
		digit = (nb2 / power_10) % 10;
		ft_putchar('0' + digit);
		power_10 /= 10;
	}
	return ;
}

/*
** this function is only here for itoa
** it really has no other purpose
*/

void		f_strrev(char *str)
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
}

/*
** itoa returns a str, that was malloc'ed
**  so the return value of itoa needs to be free'ed
** Also, we malloc a constant (12),
**  because it's the max number of digits possible
**  and it's not much ram so it's more optimized than malloc'ing
**  "personalized" amounts
*/

char		*ft_itoa(int value)
{
	char	*result;
	int		i;
	int		sign;

	sign = (value < 0) ? -1 : 1;
	result = malloc(12 * sizeof(char));
	i = 0;
	if (value == 0 && (++i))
		*result = '0';
	while (value != 0)
	{
		result[i++] = '0' + (value % 10) * sign;
		value /= 10;
	}
	if (sign == -1)
		result[i++] = '-';
	result[i++] = '\0';
	f_strrev(result);
	return (result);
}

int			ft_atoi(char *str)
{
	short int	sign;
	int			return_nb;

	return_nb = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '-'
		|| *str == '\f' || *str == '\v' || *str == '\r' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while ('0' <= *str && *str <= '9')
		return_nb = return_nb * 10 + (*(str++) - '0');
	if (*str == '.')
		while ('0' <= *str && *str <= '9')
			return_nb = return_nb * 10 + (*(str++) - '0');
	return (return_nb * sign);
}
