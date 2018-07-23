# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 20:42:37 by awoimbee          #+#    #+#              #
#    Updated: 2018/07/21 20:42:39 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OUT =	eval_expr

SRCS =	./srcs/*.c

INCLUDES =	./includes

all	:
		@make $(OUT)

$(OUT)	:
		cc -Werror -Wall -Wextra $(SRCS) -I $(INCLUDES) -o $(OUT)

clean	:
		rm -f $(OUT)

fclean	:	clean				

re	:	fclean all