/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:59:24 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/10 10:59:34 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft__strlen(char *str)
{
	int len;

	len = 0;
	while (*str != '\0')
	{
		++len;
		++str;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char *dest;
	char *dest2;

	dest = (char*)malloc(ft__strlen(src) * sizeof(char) + 1);
	dest2 = dest;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = *src;
	return (dest2);
}
