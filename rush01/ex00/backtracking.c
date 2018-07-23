/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:07:17 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/15 16:00:51 by gafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

/*
** Fuction that skips numbers that are already present.
** We don't overwrite them thanks to this
*/

t_coords	skip_not_blank(char **sudoku, t_coords pos)
{
	while (sudoku[pos.y][pos.x] != '.' && pos.x < 9)
		pos.x++;
	if (pos.x >= 9 && pos.y != 8)
	{
		pos.y += 1;
		pos.x = 0;
		return (skip_not_blank(sudoku, pos));
	}
	return (pos);
}

/*
** When going back to a previous state in backtracking,
** we need to remove what we have done to the sudoku grid upto this moment,
** this function does just that.
*/

void		clean_sudoku(char **sudoku, t_coords pos)
{
	int x;
	int y;

	x = pos.x;
	y = pos.y;
	while (y < 9)
	{
		while (x < 9)
		{
			if (sudoku[y][x] == '.')
				break ;
			if (sudoku[y][x] > '9')
				sudoku[y][x] = '.';
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

/*
** Function that checks if the proposed move is allowed,
** by the rules of sudoku. First row and column, then small square.
*/

int			checksout(char **sudoku, t_coords pos, char nb)
{
	int			x;
	int			y;
	t_coords	zone_start;

	x = -1;
	while (++x < 9)
	{
		if (sudoku[pos.y][x] == nb || sudoku[x][pos.x] == nb ||
			sudoku[pos.y][x] + 20 == nb || sudoku[x][pos.x] + 20 == nb)
			return (0);
	}
	zone_start.x = (pos.x / 3) * 3;
	zone_start.y = (pos.y / 3) * 3;
	x = zone_start.x - 1;
	y = zone_start.y - 1;
	while (++x < zone_start.x + 3)
	{
		while (++y < zone_start.y + 3)
		{
			if (sudoku[y][x] == nb || sudoku[y][x] + 20 == nb)
				return (0);
		}
		y = zone_start.y - 1;
	}
	return (1);
}

void		copy_sudoku(char **sudoku, char solution[9][9])
{
	int i;
	int j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			solution[i][j] = sudoku[i][j];
	}
}

/*
** This is the most important function in the process of backtracking,
** it's the one that call every other functions
*/

int			backtrack(char **sudoku, t_coords pos, char solution[9][9])
{
	char	i;
	int		count;

	count = 0;
	pos = skip_not_blank(sudoku, pos);
	if (pos.y >= 8 && pos.x >= 9)
	{
		copy_sudoku(sudoku, solution);
		return (1);
	}
	i = '0' + 20;
	while (++i <= '9' + 20)
	{
		if (checksout(sudoku, pos, i))
		{
			sudoku[pos.y][pos.x] = i;
			pos.x += 1;
			count = count + backtrack(sudoku, pos, solution);
			if (count > 1)
				return (count);
			pos.x -= 1;
			clean_sudoku(sudoku, pos);
		}
	}
	return (count);
}
