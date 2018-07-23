/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:09:47 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/16 16:09:49 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

typedef void(*t_fun_op)(int, int);
typedef struct	s_opp
{
	char		*op;
	t_fun_op	fun;
}				t_opp;

void			ft_add(int first, int second);
void			ft_sub(int first, int second);
void			ft_div(int first, int second);
void			ft_mul(int first, int second);
void			ft_mod(int first, int second);
void			ft_usage(int first, int second);
int				ft_strcmp(char *s1, char *s2);
int				ft_fatoi(char *str);
void			ft_putstr(char *str);
int				ft_fputnbr(int nb);
int				nbrs_valid(char *str);

#endif
