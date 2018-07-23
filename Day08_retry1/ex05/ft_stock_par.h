/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:45:20 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/12 12:45:22 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H
# include <stdlib.h>

typedef struct		s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}					t_stock_par;

#endif

#ifndef FT_STOCK_PAR_FILL_H
# define FT_STOCK_PAR_FILL_H

char				**ft_split_whitespaces(char *str);
char				*ft_strdup(char *src);
int					ft_strlen(char *str);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);

#endif
