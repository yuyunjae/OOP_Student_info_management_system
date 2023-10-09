GCC = g++ -Wall -Wextra -Werror
NAME = a.exe
INCLUDE = include
SRC = src/main.cpp src/menu.cpp src/student_db.cpp src/student.cpp
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(GCC) $^ -o $@

%.o : %.cpp menu.h student_db.h student.h
	$(GCC) -I$(INCLUDE) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY : fclean clean all re
