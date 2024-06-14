# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 14:27:32 by lmicheli          #+#    #+#              #
#    Updated: 2024/06/14 14:27:48 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BetterThanGoogle

SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)

CC = c++ -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re