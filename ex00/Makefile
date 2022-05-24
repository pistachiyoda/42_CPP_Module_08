NAME = template
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re