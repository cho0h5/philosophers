NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c parse_int.c ft_strlen.c
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
	./philo 4 1000 100 100

.PHONY: all clean fclean re
