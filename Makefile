CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=push_swap

MY_SOURCES=	main.c

MY_OBJECTS=$(MY_SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar -crs ¢@ $^

%.o: %.o
	$(CC) $(FLAGS) -c -g3 $<

clean:
	rm -rf *.o $(MY_OBJECTS)

fclean: clean
	rm -rf $(NAME)

norminette:
	norminette $(MY_SOURCES)

re: fclean all
