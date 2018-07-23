/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:07:45 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/17 18:07:47 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	char	*buffer;
	int		i;

	if (!tab || !*tab || !cmp)
		return ;
	i = -1;
	while (tab[++i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			buffer = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = buffer;
			i = -1;
		}
	}
}
