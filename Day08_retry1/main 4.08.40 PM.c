/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:50:09 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/12 19:52:33 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex06/ft_stock_par.h"
#include "ex05/ft_stock_par.h"
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int	main(int argc, char**argv)
{
	ft_show_tab(ft_param_to_tab(argc, argv));
	return (0);
}
