/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:14:37 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/22 14:14:40 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		clean_expression(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9')
		&& *str != '+' && *str != '-' && *str != '*' && *str != '/'
		&& *str != '%' && *str != '(' && *str != ')')
			*str = ' ';
		++str;
	}
}

/*
** When every operation is done inside the parenthesis,
**  this function is called to remove them,
**  since they are no longer of use
*/

void		clean_parenthesis(char *p)
{
	int		i; //go left until operator or parenthesis is found; if number is found but not these things, add * sign;

	i = 0;
	while (&p[--i] >= g_str && p[i] <= 32)
		;
	if ('0' <= p[i] && p[i] <= '9')
		*p = '*';
	else
		*p = ' ';
	while (*p && *p != ')')
		++p;
	if (*p == ')')
		*p = ' ';
}

/*
** most_nested_p : Returns a pointer to the oppening parenthesis,
**  of the most nested pair of parenthesis is the expression
*/

char		*most_nested_p(char *str)
{
	int	nb_nested_p;
	int	biggest;
	int	big_pos;
	int	i;

	nb_nested_p = 0;
	biggest = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '(')
			nb_nested_p++;
		if (str[i] == ')')
			nb_nested_p--;
		if (biggest < nb_nested_p)
		{
			biggest = nb_nested_p;
			big_pos = i;
		}
	}
	if (biggest)
		return (&str[big_pos]);
	else
		return (0);
}

/*
** This is a meta-function, calling lots of other function to spit out
**  the result of an operation from only the operator ('+', '/', ...)
*/

int			str_to_result(char *p)
{
	int i;
	int	a;
	int	b;
	int	begin;

	i = -1;
	if (!(begin = get_leftmost_nbr(p)))
		return (0);
	a = ft_atoi(&p[begin]);
	i = 1;
	b = ft_atoi(&p[i]);
	write(1, "\n Valeur de a : \e[44m", 21); ft_putnbr(a); write(1, "\e[49m", 5);
	write(1, "\n Valeur de b : \e[44m", 21); ft_putnbr(b); write(1, "\e[49m", 5);
	return (f_replace(ints_to_result(p[0], a, b), p, begin, i));
}

/*
** ints_to_result is the function doing *every* mathematical operation
*/

int			ints_to_result(char c, int a, int b)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '/')
		return (a / b);
	if (c == '*')
		return (a * b);
	if (c == '%')
		return (a % b);
	return (0);
}
