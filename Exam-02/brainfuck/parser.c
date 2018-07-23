/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:52:49 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 20:46:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned char	*g_ptr;

void	init_g_ptr(void)
{
	int i;

	i = -1;
	g_ptr = (unsigned char *)malloc(2048 * sizeof(unsigned char));
	while (++i < 2048)
		g_ptr[i] = 0;
}

int		*alloc_loops(char *inp)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = 0;
	while (*inp)
	{
		if (*inp == '[')
			++i;
		else if (*inp == ']')
			--i;
		if (i > biggest)
			biggest = i;
		++inp;
	}
	return ((int *)malloc((biggest + 2) * sizeof(int)));
}

void	sht_parser(char c)
{
	if (c == '>')
		g_ptr += 1;
	else if (c == '<')
		g_ptr -= 1;
	else if (c == '+')
		*g_ptr += 1;
	else if (c == '-')
		*g_ptr -= 1;
	else if (c == '.')
		write(1, g_ptr, 1);
}

int		jump_loops(char *p, int i)
{
	while (p[i] != ']')
	{
		i += 1;
		if (p[i] == '[')
			i = jump_loops(p, i) + 1;
	}
	return (i);
}

void	parser(char *p, int *loops)
{
	int	loop_i;
	int	i;

	i = -1;
	loop_i = -1;
	while (p[++i])
	{
		if (p[i] == '<' || p[i] == '>'
				|| p[i] == '.' || p[i] == '+' || p[i] == '-')
			sht_parser(p[i]);
		else if (p[i] == '[' && *g_ptr != 0)
			loops[++loop_i] = i;
		else if (p[i] == '[' && *g_ptr == 0)
			i = jump_loops(p, i);
		else if (p[i] == ']' && *g_ptr != 0)
			i = loops[loop_i];
		else if (p[i] == ']' && *g_ptr == 0)
			--loop_i;
	}
}
