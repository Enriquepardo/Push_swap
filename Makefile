NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -Isrc/libft/inc

SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = src/libft/src
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(SRC_DIR)/push_swap/ft_split.c \
      $(SRC_DIR)/push_swap/handle_errors.c \
      $(SRC_DIR)/push_swap/init_a_to_b.c \
      $(SRC_DIR)/push_swap/init_b_to_a.c \
      $(SRC_DIR)/push_swap/push_swap.c \
      $(SRC_DIR)/push_swap/stack_init.c \
      $(SRC_DIR)/push_swap/stack_utils.c \
      $(SRC_DIR)/commands/push.c \
	  $(SRC_DIR)/commands/rev_rotate.c \
	  $(SRC_DIR)/commands/rotate.c \
	  $(SRC_DIR)/commands/sort_stack.c \
	  $(SRC_DIR)/commands/sort_stack_utils.c \
	  $(SRC_DIR)/commands/sort_three.c \
	  $(SRC_DIR)/commands/swap.c 

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