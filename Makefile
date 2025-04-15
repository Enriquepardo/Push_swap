NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc
SRC_DIR = src
INC_DIR = inc

SRC = $(SRC_DIR)/push_swap.c \
      $(SRC_DIR)/stack_operations.c \
      $(SRC_DIR)/stack_utils.c \
      $(SRC_DIR)/sorting.c \
      $(SRC_DIR)/input_validation.c \
      $(SRC_DIR)/utils.c \
	  $(SRC_DIR)/radix_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Executable $(NAME) created."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable $(NAME) and object files cleaned."

re: fclean all

.PHONY: all clean fclean re