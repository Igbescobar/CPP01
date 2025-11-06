# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igbescobar <igbescobar@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 12:18:11 by igbescobar        #+#    #+#              #
#    Updated: 2025/11/06 12:18:56 by igbescobar       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= harl
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS= main.cpp Harl.cpp
OBJS_DIR= objs
OBJS= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
		mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re