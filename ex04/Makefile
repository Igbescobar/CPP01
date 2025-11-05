# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 14:24:22 by igngonza          #+#    #+#              #
#    Updated: 2025/11/05 14:24:23 by igngonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= replacer
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS= main.cpp File.cpp Replacer.cpp
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