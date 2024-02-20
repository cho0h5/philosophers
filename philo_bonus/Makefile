NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	main_bonus.c				\
		argument_bonus.c			\
		parse_int_bonus.c			\
		env_bonus.c					\
		panic_bonus.c				\
		parameters_bonus.c			\
		philosopher_bonus.c			\
		philosopher_fork_bonus.c	\
		philosopher_eat_bonus.c		\
		philosopher_sleep_bonus.c	\
		philosopher_die_bonus.c		\
		philosopher_spawn_bonus.c	\
		philosopher_wait_bonus.c	\
		print_bonus.c				\
		time_bonus.c				\
		ft_strlen_bonus.c			\
		ft_calloc_bonus.c			\
		ft_itoa_bonus.c				\
		ft_strjoin_bonus.c			\
		ft_strlcat_bonus.c			\
		ft_strlcpy_bonus.c

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
