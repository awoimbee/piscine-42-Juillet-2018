/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:58:30 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/10 16:58:32 by awoimbee         ###   ########.fr       */
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

void	ft_print_words_tables(char **tab)
{
	int i;

	i = -1;
	while (tab[++i] != 0)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}
}
