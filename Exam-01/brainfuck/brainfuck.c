/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 20:06:38 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 21:22:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfuck.h"

void	init(void)
{
	g_ptr = malloc(2048);
}

int		main(int argc, char **argv)
{
	(void)argc;
	init();
	parser(argv[1]);
	return (0);
}
