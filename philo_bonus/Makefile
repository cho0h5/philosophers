NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = 	main_bonus.c				\
		argument_bonus.c			\
		parse_int_bonus.c			\
		ft_strlen_bonus.c			\
		env_bonus.c					\
		panic_bonus.c				\
		parameters_bonus.c			\
		philosopher_bonus.c			\
		philosopher_fork_bonus.c	\
		philosopher_eat_bonus.c		\
		philosopher_sleep_bonus.c	\
		print_bonus.c				\
		time_bonus.c				\
#		fork.c				\
#		philosopher_die.c	\

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

test: 
	./philo_bonus 2 210 100 100

.PHONY: all clean fclean re test
