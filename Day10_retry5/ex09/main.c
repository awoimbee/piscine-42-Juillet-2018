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
#include "ft_opp.h"

void		ft_usage(int first, int second)
{
	int		i;

	(void)first;
	(void)second;
	ft_putstr("error : only [ ");
	i = -1;
	while (++i < 6)
	{
		if (g_opptab[i].op[0] != '\0')
		{
			ft_putstr(g_opptab[i].op);
			write(1, " ", 1);
		}
	}
	write(1, "] are accepted.\n", 16);
}

int			main(int argc, char **argv)
{
	unsigned long	i;

	if (argc != 4)
		return (0);
	i = 0;
	while (i < sizeof(g_opptab) / sizeof(g_opptab[0]))
	{
		if (ft_strcmp(g_opptab[i].op, argv[2]) == 0)
		{
			(*(g_opptab[i].fun))(ft_fatoi(argv[1]), ft_fatoi(argv[3]));
			return (0);
		}
		++i;
	}
	ft_usage(0, 0);
	return (0);
}
