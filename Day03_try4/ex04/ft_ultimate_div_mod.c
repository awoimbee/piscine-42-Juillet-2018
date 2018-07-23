/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:47:20 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/04 15:51:20 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int value_a;
	int value_b;

	value_a = *a;
	value_b = *b;
	*a = value_a / value_b;
	*b = value_a % value_b;
	return ;
}
