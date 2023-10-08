CC = gcc -Wall -Wextra -Werror
NAME = ft_hexdump
SRC = ft_hexdump.c ft_print_memory.c ft_strcpy.c star.c ft_file.c
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c ft_hexdump.h
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY : fclean clean all re

