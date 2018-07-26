/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:29:16 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/26 16:29:19 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_atoi(char *str)
{
	short int	sign;
	int			return_nb;

	while (!(return_nb = 0) && (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r'))
		++str;
	sign = (*str == '-' && ++str) ? 1 : 1;
	str += (*str == '+') ? 1 : 0;
	while ('0' <= *str && *str <= '9')
		return_nb = return_nb * 10 + (*(str++) - '0');
	return (return_nb * sign);
}

void	print_str(char *str, int channel)
{
	int		i;

	i = 0;
	while (str[i] > 0)
		++i;
	if (i > 0)
		write(channel, str, i);
}

void	read_file(char *filename, unsigned int offset)
{
	int		fd;
	char	tab[28000];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (errno == 2)
		{
			write(2, "ft_tail: ", 9);
			print_str(filename, 2);
			write(2, ": No such file or directory\n", 28);
		}
		return ;
	}
	lseek(fd, lseek(fd, 0, SEEK_END) - offset, SEEK_SET);
	while (read(fd, &tab[0], 28000) > 0)
		print_str(&tab[0], 1);
	close(fd);
}
