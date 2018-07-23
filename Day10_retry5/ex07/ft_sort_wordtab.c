/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:44:52 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/17 17:44:56 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' || *s2 != '\0'))
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void		ft_sort_wordtab(char **tab)
{
	char	*buffer;
	char	**table_start;
	char	**table_end;

	table_start = tab;
	table_end = tab;
	while (*table_end != 0)
		++table_end;
	--table_end;
	while (table_start < table_end)
	{
		buffer = 0;
		while (table_start < table_end)
		{
			if (ft_strcmp(*table_start, *table_end) > 0)
			{
				buffer = *table_start;
				*table_start = *table_end;
				*table_end = buffer;
			}
			++table_start;
		}
		table_start = tab;
		--table_end;
	}
}
