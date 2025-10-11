# name
NAME = 

# compiler
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD

# source files
SRCS = 
SRCS_DIR = ./
OBJS = $(SRC:.cpp=.o)
OBJS_DIR = ./
# lib
# LIB = 
# LIB_DIR = ./


all:		$(NAME)

			$(NAME):	$(OBJS)
						$(CXX) $(CXXFLAGS) -o $(NAME)

			%.o: %.cpp %.hpp
						$(CXX) $(CXXFLAGS) -c $< -o $@

# 			$(LIB):
# 						$(MAKE) -C $(LIB_DIR)


clean:
			$(RM) $(OBJS)
# 			$(MAKE) clean -C $(LIB_DIR)

fclean:		clean
			$(RM) $(NAME)
# 			$(MAKE) fclean -C $(LIB_DIR)

re:			
			fclean $(NAME)
# 			$(MAKE) re -C $(LIB_DIR)

.PHONY:		all clean fclean re
