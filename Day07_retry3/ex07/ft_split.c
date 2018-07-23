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

int				do_i_need_to_cut_here(char str, char *charset)
{
	int i;

	if (str == '\0')
		return (1);
	i = -1;
	while (charset[++i] && charset[i] != str)
		;
	if (charset[i] != str)
		return (0);
	else
		return (1);
}

char			*skip_lead_whitespace(char *str, char *charset)
{
	while (do_i_need_to_cut_here(*str, charset))
	{
		++str;
	}
	return (str);
}

int				wrds_size(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	word = str;
	while (*str != '\0' && ++str)
	{
		if (do_i_need_to_cut_here(*str, charset))
		{
			word = skip_lead_whitespace(word, charset);
			if (word - str < 0)
			{
				word = str;
				++i;
			}
		}
	}
	return (i);
}

char			**ft_split(char *str, char *charset)
{
	char	*word;
	char	**wrds;
	int		i;

	word = str;
	wrds = (char**)malloc((wrds_size(str, charset) + 1) * sizeof(char*));
	i = 0;
	while (*str != '\0' && ++str)
	{
		if (do_i_need_to_cut_here(*str, charset))
		{
			word = skip_lead_whitespace(word, charset);
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
