/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:48:57 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/09 16:49:00 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		++str;
	}
	return ;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' || *s2 != '\0'))
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	ft_sort(char **table, int size)
{
	char	*buffer;
	char	**table_start;
	char	**table_end;

	table_end = table + size - 1;
	while (table_end > table)
	{
		table_start = table;
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
		--table_end;
	}
}

int		main(int argc, char *argv[])
{
	int i;

	ft_sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		++i;
	}
	return (0);
}
