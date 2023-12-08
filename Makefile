CC=gcc

CFLAGS=-Wall -Wextra -Werror -g3

NAME=push_swap

########

MY_SOURCES_DIR=src

MY_SOURCES=		src/main.c \
				src/stack.c \
				src/automata.c

MY_OBJECTS=$(MY_SOURCES:%.c=%.o)

########

LIBFT_DIR=libft

LIBFT=libft/libft.a

########

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	make extra -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(MY_OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

norminette:
	norminette $(MY_SOURCES)

re: fclean all
