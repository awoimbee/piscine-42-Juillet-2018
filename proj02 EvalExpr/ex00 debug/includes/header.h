/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:03:56 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/21 14:03:57 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>

extern char	*g_str;

int		ft_atoi(char *str);
char	*most_nested_p(char *str);
int		ints_to_result(char c, int a, int b);
int		str_to_result(char *p);
int		f_replace(int result, char *p, int begin, int end);
void	calc_no_prio(char *p);
void	calc(char *p);
int		eval_expr(char *str);
void	f_strrev(char *str);
char	*ft_itoa(int value);
int		ft_putchar(char c);
void	ft_putnbr(int nb);
void	clean_expression(char *str);
int		get_leftmost_nbr(char *p);
void	clean_parenthesis(char *p);

#endif
