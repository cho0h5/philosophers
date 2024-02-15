NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	main.c				\
		fork.c				\
		ft_strlen.c			\
		panic.c				\
		parse_int.c			\
		env.c				\
		parameters.c		\
		philosopher.c		\
		philosopher_fork.c	\
		philosopher_eat.c	\
		philosopher_sleep.c	\
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

.PHONY: all clean fclean re
