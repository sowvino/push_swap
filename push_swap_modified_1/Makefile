NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c \
          error_handling.c \
          push_swap_init.c \
          push_swap.c \
          push.c \
          reverse_rotate.c \
          rotate.c \
          split.c \
          stack_init.c \
          stack_utilis.c \
          swap.c \
          tiny_sort.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
