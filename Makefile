NAME	= pipex

SRCS	= $(shell find ./ -maxdepth 1 -iname "*.c")
		
OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) Makefile
	@make -C libft/
	@$(CC) -Wall -Wextra -Werror $(SRCS) libft/libft.a -o pipex
	@chmod +x pipex

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re