/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 18:32:42 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 19:06:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	char first_half;
	char second_half;

	first_half = octet & 0b11110000;
	second_half = octet & 0b00001111;
	first_half /= 16;
	second_half *= 16;
	octet = second_half | first_half;
	return (octet);
}
