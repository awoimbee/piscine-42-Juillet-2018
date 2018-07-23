/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:22:51 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/10 13:22:54 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		tmp_size;
	char	*source;

	source = src;
	tmp_size = size;
	if (size != 0)
	{
		while (--tmp_size > 0)
		{
			*dest = *src;
			++dest;
			++src;
			if (*(dest - 1) == '\0')
				break ;
		}
	}
	if (tmp_size == 0)
	{
		if (size > 0)
			*dest = '\0';
		while (*src)
			++src;
		++src;
	}
	return (src - source - 1);
}

char			*skip_lead_whitespace(char *str)
{
	while (*str == ' '
		|| *str == 9
		|| *str == '\n')
	{
		++str;
	}
	return (str);
}

int				wrds_size(char *str)
{
	int		i;
	char	*word;

	i = 0;
	word = str;
	while (*str != '\0' && ++str)
	{
		if (*str == 32 || *str == 9 || *str == '\n' || *str == '\0')
		{
			word = skip_lead_whitespace(word);
			if (word - str < 0)
			{
				word = str;
				++i;
			}
		}
	}
	return (i);
}

char			**ft_split_whitespaces(char *str)
{
	char	*word;
	char	**wrds;
	int		i;

	word = str;
	wrds = (char**)malloc((wrds_size(str) + 1) * sizeof(char*));
	i = 0;
	while (*str != '\0' && ++str)
	{
		if (*str == 32 || *str == 9 || *str == '\n' || *str == '\0')
		{
			word = skip_lead_whitespace(word);
			if (word - str < 0)
			{
				wrds[i] = (char*)malloc((str - word) * sizeof(char));
				ft_strlcpy(wrds[i], word, 1 + str - word);
				word = str;
				++i;
			}
		}
	}
	wrds[i] = 0;
	return (wrds);
}
