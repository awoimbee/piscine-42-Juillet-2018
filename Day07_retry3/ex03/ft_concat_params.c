/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:20:57 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/10 13:21:00 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int word_nb;

	word_nb = 0;
	while (*str != '\0')
	{
		++word_nb;
		++str;
	}
	return (word_nb);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*result;

	result = dest;
	while (*dest != '\0')
	{
		++dest;
	}
	while (*src != '\0')
	{
		*dest = *src;
		++src;
		++dest;
	}
	*dest = *src;
	return (result);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	char	*result;
	int		args_size;
	int		n;

	i = 1;
	args_size = 0;
	while (i < argc)
	{
		args_size += ft_strlen(argv[i]);
		++i;
	}
	result = (char*)malloc(args_size * sizeof(char) + 1);
	i = 1;
	n = 0;
	while (i < argc)
	{
		ft_strcat(result, argv[i]);
		if (++i < argc)
			ft_strcat(result, "\n");
	}
	ft_strcat(result, "\0");
	return (result);
}
