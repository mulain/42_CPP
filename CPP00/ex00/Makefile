# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 14:41:05 by wmardin           #+#    #+#              #
#    Updated: 2022/12/28 14:46:33 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CC = gcc
CFLAGS = -g -fsanitize=address
EFLAGS = -Wall -Wextra -Werror
LIBFLAGS =
RM = rm -rf

PINK	:= \033[0;35m
PURPLE	:= \033[0;34m
BLUE	= \033[94m
RESET	:= \033[0m

SRC =	megaphone.cpp
OBJ	=	$(addprefix obj/, $(SRC:src/%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(EFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(LIBFLAGS) $(RL_FLAG)
	@echo "$(BLUE)$(NAME) compiled.$(RESET)\n"

$(LIBFT):
	@make --no-print-directory -C src/libft

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CC) $(EFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) obj
	@echo "$(PINK)✨Minishell successfully cleaned!✨$(RESET)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

git:
	git add .
	git commit -m "auto add & push"
	git push
	@echo "$(BLUE)git auto add & push performed.$(RESET)"

mgit:
	git add .
	@read -p "Enter the commit message: " halp; \
	git commit -m "$$halp"
	git push
	@echo "$(BLUE)git auto add & push with message performed.$(RESET)"

.SILENT: $(OBJ)