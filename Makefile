NAME			=	fftconvolve
SOURCE			=	src/fftconvolve.cpp			\
					src/main.cpp				\
					src/utils.cpp				\


CXX				= 	c++
OBJECT			=	$(SOURCE:.cpp=.o)
CXXFLAGS		= 	-g -Wall -Wextra -Werror
RM				=	rm -rf

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	$(CXX) $(CXXFLAGS) $(OBJECT) -o $(NAME)

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re