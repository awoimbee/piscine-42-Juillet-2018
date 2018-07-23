/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:44:37 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/09 16:44:41 by awoimbee         ###   ########.fr       */
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

int		main(int argc, char *argv[])
{
	int i;

	i = argc;
	while (--i > 0)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}
