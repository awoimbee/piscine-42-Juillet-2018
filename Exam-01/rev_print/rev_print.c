/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 18:18:18 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 18:25:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int i;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = -1;
	while (argv[1][++i])
		;
	--i;
	while (i >= 0)
	{
		ft_putchar(argv[1][i]);
		--i;
	}
	ft_putchar('\n');
	return (0);
}
