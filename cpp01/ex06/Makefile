# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 11:02:19 by lmicheli          #+#    #+#              #
#    Updated: 2024/04/05 11:17:23 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++ -std=c++98 -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re