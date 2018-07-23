/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:59:00 by skiessli          #+#    #+#             */
/*   Updated: 2018/07/15 16:01:27 by gafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "backtracking.h"

int			check_array(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 10)
		return (0);
	i = -1;
	while (++i < 9)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '.' && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
	}
	return (1);
}

/*
** We filled the sudoku grid with numbers too great to be shown as ascii digits
** This function undoes this.
*/

void		print_sudoku(char sudoku[9][9])
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < 9)
	{
		while (x < 9)
		{
			if ('9' < sudoku[y][x])
				sudoku[y][x] -= 20;
			write(1, &sudoku[y][x], 1);
			if (x < 8)
				write(1, " ", 1);
			++x;
		}
		x = 0;
		write(1, "\n", 1);
		++y;
	}
}

int			main(int argc, char **argv)
{
	t_coords	start;
	char		solution[9][9];

	++argv;
	start.x = 0;
	start.y = 0;
	if (check_array(argc, argv) && backtrack(argv, start, solution) == 1)
	{
		print_sudoku(solution);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (1);
}
