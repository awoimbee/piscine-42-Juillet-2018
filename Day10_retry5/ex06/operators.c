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

int			ft_add(int first, int second)
{
	return (first + second);
}

int			ft_sub(int first, int second)
{
	return (first - second);
}

int			ft_divide(int first, int second)
{
	return (first / second);
}

int			ft_multiply(int first, int second)
{
	return (first * second);
}

int			ft_modulo(int first, int second)
{
	return (first % second);
}
