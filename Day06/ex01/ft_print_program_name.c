/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:29:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/09 16:30:40 by awoimbee         ###   ########.fr       */
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
	(void)argc;
	ft_putstr(argv[0]);
	ft_putchar('\n');
	return (0);
}
