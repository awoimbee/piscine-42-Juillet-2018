/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 20:11:02 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 21:23:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfuck.h"

void	dothething(char c)
{
	if (c == '+')
		*g_ptr += 1;
	if (c == '-')
		*g_ptr -= 1;
	if (c == '>')
		++g_ptr;
	if (c == '<')
		--g_ptr;
	if (c == '.')
		write(1, g_ptr, 1);
}

void	parser(char *in)
{
	int i;
	int lastloop[24];
	int j;

	i = 0;
	j = 0;
	while (in[i])
	{
		if (in[i] == '[' && *g_ptr != 0 && ++j)
			lastloop[j - 1] = i;
		else if (in[i] == '[' && *g_ptr == 0)
		{
			while (in[i + 1] && in[i + 1] != ']')
				++i;
		}
		else if (in[i] == ']' && *g_ptr != 0)
		{
			i = lastloop[j - 1];
		}
		else if (in[i] == ']' && *g_ptr == 0)
			--j;
		else
			dothething(in[i]);
		++i;
	}
}
