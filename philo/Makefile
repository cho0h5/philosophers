NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = 	main.c				\
		fork.c				\
		thread.c			\
		ft_strlen.c			\
		panic.c				\
		parse_int.c			\
		env.c				\
		parameters.c		\
		philosopher.c		\
		philosopher_die.c	\
		argument.c			\
		print.c				\
		time.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

test: all
	./philo 4 210 100 100

.PHONY: all clean fclean re test
