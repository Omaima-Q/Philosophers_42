# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 17:40:49 by omaimaqaroo       #+#    #+#              #
#    Updated: 2025/06/11 17:40:52 by omaimaqaroo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Program name
NAME = philo

# Compiler and CFlags
CC      = gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM      = rm -f

# Directories
INC     = inc/
SRC_DIR	= src/
OBJ_DIR	= obj/

# Source Files
SRC	= init_input.c \
	  threads_handler.c \
	  philo_monitor.c \
	  parse.c \
	  philo.c \
	  status_print.c \
	  protection.c \
	  start_simu.c \
	  utils.c

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

# Object files, This adds the src/ directory path to each filename listed in SRC, 
# effectively constructing the full path to each source file. This is useful for 
# organizing projects and ensuring the correct paths are used during the build process.

OBJ 	= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Build rules, transforms each .c file path into a corresponding .o file path in the
# obj/ directory. This ensures the objects are stored where they should be, 
# following a structured build process.

all: 	$(NAME)

$(NAME): $(OBJ)
	 @$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) -r $(OBJ_DIR)

fclean: 	clean
		@$(RM) $(NAME)
		@$(RM) src/a.out

re: 		fclean all

# Phony targets represent actions not files
.PHONY: 	all clean fclean re leaks valgrind_leaks help

# # Checks for memory leaks
# leaks: re
# 	@echo "\033[1;33m\nChecking for memory leaks...\033[0m"
# 	leaks --atExit -- ./$(NAME) 5 800 200 200 3

# valgrind_leaks: re
# 	@echo "\033[1;33m\nChecking for memory leaks with valgrind...\033[0m"
# 	valgrind --leak-check=full ./$(NAME) 5 800 200 200 3

# help:
# 	@echo "\033[1;35mMake options:\033[0m"
# 	@echo "\033[1;36mmake all\033[0m   Compile the program"
# 	@echo "\033[1;36mmake clean\033[0m   Remove object files"
# 	@echo "\033[1;36mmake fclean\033[0m   Remove object files and the executable"
# 	@echo "\033[1;36mmake re\033[0m   Re-build program from fresh after fclean"
# 	@echo "\033[1;36mmake leaks\033[0m   Check for memory leaks in macOS"
# 	@echo "\033[1;36mmake valgrind_leaks\033[0m   Check for leaks with valgrind in linux"
