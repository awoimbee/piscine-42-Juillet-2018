/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:16:25 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/05 15:56:35 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int		buffer;
	int		*str_start;
	int		*str_end;

	str_end = tab + size - 1;
	while (str_end > tab)
	{
		str_start = tab;
		buffer = 0;
		while (buffer != 42)
		{
			buffer = 42;
			while (str_start < str_end)
			{
				if (*str_start > *str_end)
				{
					buffer = *str_start;
					*str_start = *str_end;
					*str_end = buffer;
				}
				++str_start;
			}
		}
		--str_end;
	}
}
