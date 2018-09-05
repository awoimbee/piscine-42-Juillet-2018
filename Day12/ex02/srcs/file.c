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
	sign = (*str == '-' && ++str) ? -1 : 1;
	str += (*str == '+') ? 1 : 0;
	while ('0' <= *str && *str <= '9')
		return_nb = return_nb * 10 + (*(str++) - '0');
	return (return_nb * sign);
}

int	ft_strlen(char *str)
{
	int word_nb;

	word_nb = 0;
	while (*str != '\0')
	{
		++word_nb;
		++str;
	}
	return (word_nb);
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

int		ft_open(char* filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (errno == 2)
		{
			write(2, "ft_tail: ", 9);
			print_str(filename, 2);
			write(2, ": No such file or directory\n", 28);
		}
	}
	return (fd);		
}

void	reset_buff(char* buffer, int size)
{
	while(size--)
	{
		buffer[size] = '\0';
	}
}

