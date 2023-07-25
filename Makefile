NAME	= pipex

SRCS	= $(shell find ./ -maxdepth 1 -iname "*.c")
		
OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME):
	@cd libft && make
	@$(CC) -Wall -Wextra -Werror $(SRCS) libft/libft.a -o pipex
	@chmod +x pipex

clean:
	@cd libft && make clean
	@rm -f $(OBJS)

fclean: clean
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re