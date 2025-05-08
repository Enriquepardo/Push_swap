# Makefile - raíz del proyecto push_swap

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -Isrc/libft/inc

SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = src/libft/src
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(SRC_DIR)/push_swap.c \
      $(SRC_DIR)/stack_operations.c \
      $(SRC_DIR)/stack_utils.c \
      $(SRC_DIR)/sorting.c \
      $(SRC_DIR)/input_validation.c \
      $(SRC_DIR)/quick_sort.c \
      $(SRC_DIR)/utils.c \
      $(SRC_DIR)/radix_utils.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Executable $(NAME) created."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Executable $(NAME) and object files cleaned."

re: fclean all

.PHONY: all clean fclean re
