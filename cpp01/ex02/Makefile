NAME = pointer

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP

SRCS = main.cpp
SRCS_DIR = ./
OBJS = $(SRCS_DIR)$(SRCS:.cpp=.o)
OBJS_DIR = ./

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS_DIR)$(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

all: $(NAME)

clean:
			$(RM) $(OBJS_DIR)$(OBJS) $(OBJS_DIR)$(OBJS:.o=.d)

fclean: clean
			$(RM) $(NAME) $(OBJS_DIR)$(OBJS:.o=.d)

re: fclean $(NAME)

.PHONY:		all clean fclean re
