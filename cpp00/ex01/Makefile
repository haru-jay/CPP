# name
NAME = PhoneBook

# compiler
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP

# source files
SRCS = PhoneBook.cpp
SRCS_DIR = ./
OBJS = $(SRCS_DIR)$(SRCS:.cpp=.o)
OBJS_DIR = ./
# lib
# LIB = 
# LIB_DIR = ./

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS_DIR)$(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 자동 의존성 파일 포함
-include $(OBJS:.o=.d)

all: $(NAME)
# 			$(LIB):
# 						$(MAKE) -C $(LIB_DIR)


clean:
			$(RM) $(OBJS_DIR)$(OBJS) $(OBJS_DIR)$(OBJS:.o=.d)
# 			$(MAKE) clean -C $(LIB_DIR)

fclean: clean
			$(RM) $(NAME) $(OBJS_DIR)$(OBJS:.o=.d)
# 			$(MAKE) fclean -C $(LIB_DIR)

re: fclean $(NAME)
# 			$(MAKE) re -C $(LIB_DIR)

.PHONY:		all clean fclean re
