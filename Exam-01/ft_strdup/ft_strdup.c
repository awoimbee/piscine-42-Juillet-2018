/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:11:34 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 19:20:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*output;
	int		i;

	i = -1;
	while (src[++i])
		;
	output = malloc((i + 1) * sizeof(char));
	i = -1;
	while (src[++i])
		output[i] = src[i];
	output[i] = src[i];
	return (output);
}
