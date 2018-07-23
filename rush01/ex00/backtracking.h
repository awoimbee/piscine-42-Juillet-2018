/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:16:06 by skiessli          #+#    #+#             */
/*   Updated: 2018/07/15 15:46:27 by gafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_H
# define BACKTRACKING_H

typedef struct	s_coords {
	int x;
	int y;
}				t_coords;

int				backtrack(char **sudoku, t_coords pos, char solution[9][9]);

#endif
