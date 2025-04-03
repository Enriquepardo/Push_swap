NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc
SRC_DIR = src/
INC_DIR = inc/

SRCS = $(SRC_DIR)push_swap.c \
       $(SRC_DIR)operations.c \
       $(SRC_DIR)utils.c \
       $(SRC_DIR)sort_small.c \
       $(SRC_DIR)sort_large.c \
       $(SRC_DIR)stack_operations.c

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Executable $(NAME) created."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable $(NAME) and object files cleaned."

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re