/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:07:21 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/17 14:07:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void		ft_add(int first, int second)
{
	ft_fputnbr(first + second);
}

void		ft_sub(int first, int second)
{
	ft_fputnbr(first - second);
}

void		ft_div(int first, int second)
{
	if (second == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		ft_fputnbr(first / second);
}

void		ft_mul(int first, int second)
{
	ft_fputnbr(first * second);
}

void		ft_mod(int first, int second)
{
	if (second == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_fputnbr(first % second);
}
