/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:13:38 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/07 18:13:45 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		respect_rules(int nw_q_row);
int		re_queen_puzzle(int queen_and_row_nb);
int		ft_putchar(char c);

/*
** g_q_col[row] = the column of the queen at this row
*/
int		g_q_col[8];

/*
** here is our main, recursive function
*/

int		re_queen_puzzle(int queen_and_row_nb)
{
	static int	result = 0;
	int			row;

	if (queen_and_row_nb == 8)
		++result;
	else
	{
		row = -1;
		while (++row < 8)
		{
			g_q_col[queen_and_row_nb] = row;
			if (respect_rules(queen_and_row_nb))
				re_queen_puzzle(queen_and_row_nb + 1);
		}
	}
	return (result);
}

/*
** Here we test if new queen is in the same column or diagonal as old queen
*/

int		respect_rules(int nw_q_row)
{
	int old_q_row;

	old_q_row = 0;
	while (old_q_row < nw_q_row)
	{
		if (g_q_col[old_q_row] == g_q_col[nw_q_row])
			return (0);
		if ((g_q_col[old_q_row] - g_q_col[nw_q_row]) == (nw_q_row - old_q_row))
			return (0);
		if ((g_q_col[nw_q_row] - g_q_col[old_q_row]) == (nw_q_row - old_q_row))
			return (0);
		++old_q_row;
	}
	return (1);
}

int		ft_eight_queens_puzzle(void)
{
	return (re_queen_puzzle(0));
}
