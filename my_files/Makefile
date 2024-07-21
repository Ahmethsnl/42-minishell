NAME = minishell
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
M_SRC = ./src/minishell.c
SRC = $(M_SRC)
OBJ = $(SRC:.c=.o)
READLINE = -L./lib/readline/lib -I./lib/readline/include/readline -lreadline 
DIR     = $(shell echo $(PWD))
RM = rm -rf
RL = ./lib/readline/lib/libreadline.a
LIBFT = ./lib/libft/libft.a
LIBFT_OBJS = ./lib/libft/*.o


all: $(NAME)

$(NAME): $(RL) $(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(READLINE) $(LIBFT)

$(RL):
		@echo "Downloading readline"
		@curl -O https://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
		@tar -xvf readline-8.2-rc1.tar.gz
		@$(RM) readline-8.2-rc1.tar.gz
		@cd readline-8.2-rc1 && ./configure --prefix=$(DIR)/lib/readline && make && make install
		@$(RM) readline-8.2-rc1
		@ echo "Readline installed"

r : all clean
		@./$(NAME)

RLclean:
		@$(RM) lib/readline
		@echo "Readline removed"

clean:
		@$(RM) $(OBJ) $(LIBFT_OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean all