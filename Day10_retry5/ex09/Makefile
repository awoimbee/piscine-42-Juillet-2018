# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 14:58:49 by awoimbee          #+#    #+#              #
#    Updated: 2018/07/17 14:58:51 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT =	ft_advanced_do-op

SRCS =	./main.c		\
		./operators.c	\
		./functions.c

INCLUDES =	./doop.h

all	:
		@make $(OUT)

$(OUT)	:
		gcc -Werror -Wall -Wextra $(SRCS) -I $(INCLUDES) -o $(OUT)

clean	:
		rm -f $(OUT)

fclean	:	clean				

re	:	fclean all