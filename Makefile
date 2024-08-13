# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#              #
#    Updated: 2024/08/13 11:01:31 by pdeson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK_NAME = checker
CC = @cc
CFLAGS = -Werror -Wall -Wextra
LIBFT_LIB = libft/libft.a

SRCES_DIR = sources/
BONUS_DIR = checker/
OBJ_DIR = .objs/

SRCES = $(wildcard $(SRCES_DIR)*.c)
OBJS = $(patsubst $(SRCES_DIR)%.c, $(OBJ_DIR)%.o , $(SRCES))
SRCES_BONUS = $(wildcard $(BONUS_DIR)*.c)
OBJS_BONUS = $(patsubst $(BONUS_DIR)%.c, $(OBJ_DIR)%.o , $(SRCES_BONUS))


all: $(NAME)

bonus: $(CHECK_NAME)

$(OBJ_DIR)%.o: $(SRCES_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJS)
	@make -C libft/ all --no-print-directory
	@echo "Library libft created\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "Compilation Push_Swap made\n"

$(CHECK_NAME): $(OBJS_BONUS)
	@make -C libft/ all --no-print-directory
	@echo "Library libft created\n"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_LIB) -o $(CHECK_NAME)
	@echo "Compilation Push_Swap made\n"

clean:
	@make -C libft/ clean --no-print-directory
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rmdir $(OBJ_DIR) 2>/dev/null || true

fclean: clean
	@make -C libft/ fclean --no-print-directory
	@rm -f $(NAME) $(CHECK_NAME)

re: fclean all

ex: re clean

.PHONY: all clean fclean re ex bonus
