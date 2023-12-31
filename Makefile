NAME	= pipex

CFLAGS	= -Wall -Wextra -Werror
LIBFT	= libft/libft.a

SRCS	= pipex_utils.c \
			pipex.c
OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o pipex

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re