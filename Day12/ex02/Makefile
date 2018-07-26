# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/07/16 11:55:23 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	ft_tail

SRCS	=	./srcs/*.c

HEADERS =	./incs/

all	:
		@make $(NAME)

$(NAME)	:
		gcc -Werror -Wall -Wextra $(SRCS) -I $(HEADERS) -o $(NAME)

clean	:
		@echo "nothing to clean."

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
