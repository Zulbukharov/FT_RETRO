# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 13:58:02 by azulbukh          #+#    #+#              #
#    Updated: 2018/10/07 15:07:32 by azulbukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_retro
FLAGS = -Wall -Werror -Wextra
SRC = main.cpp Object.cpp Player.cpp Game.cpp Enemy.cpp Node.cpp
CC = clang++
OSRC =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OSRC)
	clang++ -o $(NAME) $(FLAGS) -lncurses $(OSRC)

%.o: %.cpp
	clang++ $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
