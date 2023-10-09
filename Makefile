GCC = g++ -Wall -Wextra -Werror
NAME = a.exe
INCLUDE = include
SRC = src/main.cpp src/menu.cpp src/student_db.cpp src/student.cpp
OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(GCC) $^ -o $@

%.o : %.cpp include/menu.h include/student_db.h include/student.h
	$(GCC) -I$(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY : fclean clean all re
