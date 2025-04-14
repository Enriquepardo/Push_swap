NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc
SRC_DIR = src/
INC_DIR = inc/

SRCS = $(SRC_DIR)push_swap.c \
       $(SRC_DIR)ops_swap.c \
	   $(SRC_DIR)ops_push_rotate.c \
	   $(SRC_DIR)ops_reverse_rotate.c \
       $(SRC_DIR)stack.c
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