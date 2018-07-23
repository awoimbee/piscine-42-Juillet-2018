/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:09:47 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/16 18:09:49 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		++str;
	}
}

int			ft_fatoi(char *str)
{
	short int	sign;
	int			return_nb;

	while (!(return_nb = 0) && (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r'))
		++str;
	sign = (*str == '-' && ++str) ? -1 : 1;
	str += (*str == '+') ? 1 : 0;
	while ('0' <= *str && *str <= '9')
		return_nb = return_nb * 10 + (*(str++) - '0');
	return (return_nb * sign);
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' || *s2 != '\0'))
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int			ft_fputnbr(int nb)
{
	long int	num;
	long int	power_10;
	long int	nb2;
	char		c;

	nb2 = nb;
	if (nb2 < 0)
	{
		write(1, "-", 1);
		nb2 = nb2 * -1;
	}
	power_10 = 1;
	num = nb2;
	while (num > 9 && (power_10 *= 10))
		num /= 10;
	while (power_10 > 0)
	{
		nb = (nb2 / power_10) % 10;
		c = '0' + nb;
		write(1, &c, 1);
		power_10 /= 10;
	}
	return (write(1, "\n", 1));
}
