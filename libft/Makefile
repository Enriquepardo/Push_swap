NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../inc

SRCS = \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

SRCLST = \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

OBJS = $(SRCS:.c=.o)
OBJSLST = $(SRCLST:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

lists:
	@$(CC) $(CFLAGS) -c $(SRCLST)
	@ar rcs $(NAME) $(OBJS) $(OBJSLST)
	@echo "Library $(NAME) with lists created."

clean:
	@rm -f $(OBJS) $(OBJSLST)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) and object files cleaned."

re: fclean all

.PHONY: all bonus clean fclean re