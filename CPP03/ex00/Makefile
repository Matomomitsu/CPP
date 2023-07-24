# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 15:35:48 by mtomomit          #+#    #+#              #
#    Updated: 2023/05/27 17:00:30 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap

# Compilation
CC = c++

# Compilation flags
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

RM		= rm -rf

SOURCES = ClapTrap.cpp \
			main.cpp
SRCS_PATH = ./
SRCS =	$(addprefix $(SRC_PATH), $(SOURCES))

OBJS_PATH = ./objs/
OBJS = $(addprefix $(OBJS_PATH), $(SOURCES:.cpp=.o))

HEADER = ClapTrap.hpp

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.cpp
					@mkdir -p objs
					$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_PATH)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
