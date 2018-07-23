/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:08:46 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/16 16:08:50 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

t_fun_op	ft_operator(char c)
{
	int (*func_ptr[5])(int, int);

	func_ptr[0] = ft_add;
	func_ptr[1] = ft_sub;
	func_ptr[2] = ft_divide;
	func_ptr[3] = ft_multiply;
	func_ptr[4] = ft_modulo;
	if (c == '+')
		return (func_ptr[0]);
	if (c == '-')
		return (func_ptr[1]);
	if (c == '/')
		return (func_ptr[2]);
	if (c == '*')
		return (func_ptr[3]);
	if (c == '%')
		return (func_ptr[4]);
	return (0);
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

int			stop(int reason)
{
	if (reason == 1)
		write(1, "Stop : division by zero\n", 24);
	if (reason == 2)
		write(1, "Stop : modulo by zero\n", 22);
	return (0);
}

int			main(int argc, char **argv)
{
	int (*func_ptr)(int, int);
	int first;
	int second;

	if (argc != 4)
		return (0);
	if (argv[2][1] == '\0' && (func_ptr = ft_operator(argv[2][0])))
		;
	else
		return (write(1, "0\n", 2));
	first = ft_fatoi(argv[1]);
	second = ft_fatoi(argv[3]);
	if (argv[2][0] == '/' && second == 0)
		return (stop(1));
	if (argv[2][0] == '%' && second == 0)
		return (stop(2));
	first = (func_ptr)(first, second);
	return (ft_fputnbr(first));
}
