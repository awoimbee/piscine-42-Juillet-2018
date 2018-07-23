/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:44:49 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 19:59:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	int	buffer;
	int	*start;
	int	*end;

	start = tab;
	end = tab + size - 1;
	while (start < end)
	{
		while (start < end)
		{
			if (*start > *end)
			{
				buffer = *start;
				*start = *end;
				*end = buffer;
			}
			++start;
		}
		start = tab;
		--end;
	}
}
