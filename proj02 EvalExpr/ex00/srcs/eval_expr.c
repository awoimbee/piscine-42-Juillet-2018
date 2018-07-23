/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:07:56 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/21 14:07:57 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**  QUELQUE CHOSE COMME 2(5) N'EST PAS GERE !!!!!
*/

char		*g_str;

/*
** f_replace : replaces on operation (example : a + b) with it's result
**  so with a + b = c, "a + b" is replaced by "c"
*/

int			f_replace(int result, char *p, int begin, int end)
{
	char	*str_result;
	int		i;

	while ('0' > p[end] || p[end] > '9')
		++end;
	while ('0' <= p[end] && p[end] <= '9')
		++end;
	i = begin;
	while (i < end)
	{
		p[i] = ' ';
		++i;
	}
	i = 0;
	str_result = ft_itoa(result);
	while (str_result[i])
		p[begin++] = str_result[i++];
	free(str_result);
	return (1);
}

/*
** get_leftmost_nbr gets a pointer to the operator ('+', '-', '*', ..)
** it returns the number at the left of the operator (-2 or 42 or ...),
**  in the form of an int
*/

int			get_leftmost_nbr(char *p)
{
	int		t;
	int		i;
	int		tmp;

	t = 0;
	i = -1;
	tmp = 0;
	while (p[i] != '(' && p[i] != ')' && p[i] != '+'
	&& p[i] != '-' && &p[i] >= g_str)
	{
		while (&p[i] >= g_str && (p[i] >= '0' && p[i] <= '9'))
		{
			t = 1;
			--i;
		}
		while (t == 1 && p[i] == ' ' && &p[i] > g_str)
			--i;
		if (t == 1 && (p[i] == '-' || p[i] == '+') && !get_leftmost_nbr(&p[i]))
			return (i);
		if (t == 1)
			return (i + 1);
		--i;
	}
	return (0);
}

/*
** This function handles simple operations (+,-),
**  inside the parenthesis pointed by *p
*/

void		calc_no_prio(char *p)
{
	int	i;
	int	t;

	i = -1;
	t = 0;
	while (p[++i] && ((p[i] != '+' && p[i] != '-' && p[i] != ')') || t != 1))
		if ('0' <= p[i] && p[i] <= '9')
			t = 1;
	if (p[i] == '\0' || p[i] == ')')
		return ;
	else
	{
		if (!str_to_result(p + i))
			return ;
		calc(p);
	}
}

/*
** This function handles complex operations (*,/,%),
**  inside the parenthesis pointed by *p
**  if no complex operation is detected, it calls calc_no_prio(char *p)
*/

void		calc(char *p)
{
	int	i;

	i = -1;
	while (p[++i] && p[i] != '/' && p[i] != '*' && p[i] != '%' && p[i] != ')')
		;
	if (p[i] == '\0' || p[i] == ')')
		calc_no_prio(p);
	else
	{
		str_to_result(p + i);
		calc(p);
	}
}

int			eval_expr(char *str)
{
	char	*p;

	g_str = str;
	clean_expression(str);
	while ((p = most_nested_p(str)) != 0)
	{
		calc(p);
		clean_parenthesis(p);
	}
	calc(str);
	return (ft_atoi(str));
}
