NAME	= pipex

CFLAGS = -Wall -Wextra -Werror

SRCS	= $(shell find ./ -maxdepth 1 -iname "*.c")
OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o pipex
	@chmod +x pipex

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, foo