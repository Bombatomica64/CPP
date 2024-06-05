# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 10:54:56 by lmicheli          #+#    #+#              #
#    Updated: 2024/06/05 10:55:15 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = burocracy_is_more_fun

SRCS = main.cpp Bureaucrat.cpp

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