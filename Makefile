NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -Isrc/libft/inc

SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(SRC_DIR)/push_swap/handle_errors.c \
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
	  $(SRC_DIR)/commands/swap.c \
	  $(LIBFT_DIR)/src/ft_alloc/ft_bzero.c \
	  $(LIBFT_DIR)/src/ft_alloc/ft_calloc.c \
	  $(LIBFT_DIR)/src/ft_alloc/ft_split.c \
	  $(LIBFT_DIR)/src/ft_alloc/ft_substr.c \
	  $(LIBFT_DIR)/src/ft_char/ft_isalnum.c \
	  $(LIBFT_DIR)/src/ft_char/ft_isalpha.c \
	  $(LIBFT_DIR)/src/ft_char/ft_isascii.c \
	  $(LIBFT_DIR)/src/ft_char/ft_isdigit.c \
	  $(LIBFT_DIR)/src/ft_char/ft_isprint.c \
	  $(LIBFT_DIR)/src/ft_conv/ft_atoi.c \
	  $(LIBFT_DIR)/src/ft_conv/ft_itoa.c \
	  $(LIBFT_DIR)/src/ft_conv/ft_tolower.c \
	  $(LIBFT_DIR)/src/ft_conv/ft_toupper.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstadd_back.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstadd_front.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstclear.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstdelone.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstiter.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstlast.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstmap.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstnew.c \
	  $(LIBFT_DIR)/src/ft_lst/ft_lstsize.c \
	  $(LIBFT_DIR)/src/ft_mem/ft_memchr.c \
	  $(LIBFT_DIR)/src/ft_mem/ft_memcmp.c \
	  $(LIBFT_DIR)/src/ft_mem/ft_memcpy.c \
	  $(LIBFT_DIR)/src/ft_mem/ft_memmove.c \
	  $(LIBFT_DIR)/src/ft_mem/ft_memset.c \
	  $(LIBFT_DIR)/src/ft_printf/ft_printf.c \
	  $(LIBFT_DIR)/src/ft_printf/ft_putchar.c \
	  $(LIBFT_DIR)/src/ft_printf/ft_puthex.c \
	  $(LIBFT_DIR)/src/ft_printf/ft_putnbr.c \
	  $(LIBFT_DIR)/src/ft_printf/ft_putptr.c \
	  $(LIBFT_DIR)/src/ft_printf/ft_putstr.c \
	  $(LIBFT_DIR)/src/ft_printf/ft_putunbr.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strchr.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strdup.c \
	  $(LIBFT_DIR)/src/ft_str/ft_striteri.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strjoin.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strlcat.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strlcpy.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strlen.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strmapi.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strncmp.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strnstr.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strrchr.c \
	  $(LIBFT_DIR)/src/ft_str/ft_strtrim.c \
	  $(LIBFT_DIR)/src/get_next_line/get_next_line.c
	
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