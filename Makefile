CC = gcc -Wall -Wextra -Werror
NAME = a.exe
SRC = main.cpp menu.cpp student_db.cpp student.cpp
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c menu.h student_db.h student.h
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY : fclean clean all re

//수정하기
