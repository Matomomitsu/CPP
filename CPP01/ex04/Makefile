# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 16:15:49 by mtomomit          #+#    #+#              #
#    Updated: 2023/04/27 23:59:47 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
TEST_NAME = ./test/tests

# Compilation
CC = c++

# Compilation flags
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

RM		= rm -rf

TEST = tests.cpp
TEST_PATH = ./test/
TESTS =	$(addprefix $(TESTS_PATH), $(TEST_NAME))

SOURCES =	main.cpp
SRCS_PATH = ./
SRCS =	$(addprefix $(SRC_PATH), $(SOURCES))

OBJS_PATH = ./objs/
OBJS = $(addprefix $(OBJS_PATH), $(SOURCES:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.cpp
					@mkdir -p objs
					$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_PATH)

fclean: clean
		$(RM) $(NAME)

re: fclean all

test: all
	@mkdir -p test
	$(CC) $(CFLAGS) $(TEST) -o $(TEST_NAME)
	./test/tests
	./replace ./test/test.txt Lorem b
	sed 's/Lorem/b/g' ./test/test.txt > ./test/test.txt.sed
	diff ./test/test.txt.sed ./test/test.txt.replace

fclean_test:
	$(RM) test
	$(RM) test.cpp

.PHONY: all clean fclean
