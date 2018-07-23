/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:07:49 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/08 17:07:51 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char	*result;

	result = dest;
	while (*dest != '\0')
	{
		++dest;
	}
	while (*src != '\0' && nb > 0)
	{
		*dest = *src;
		++src;
		++dest;
		--nb;
	}
	*dest = '\0';
	return (result);
}
