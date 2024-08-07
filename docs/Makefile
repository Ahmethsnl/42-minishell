NAME = minishell
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
M_SRC = src/meta.c src/quote.c src/separator.c src/token.c \
	src/token_add.c src/token_append.c src/token_append_util.c src/token_util.c \
	src/util.c src/dollar.c src/dollar_util.c src/dollar_handle.c \
	src/assign_token_types.c src/lexer.c src/error.c src/exec.c src/path.c \
	src/ft_split.c src/redirect.c src/redirect_handle.c \
	src/built_in.c src/cd.c src/echo.c src/env.c src/exit.c src/export.c \
	src/pwd.c src/syntax_check_util.c src/syntax_check.c src/unset.c \
	src/signal.c src/dispose.c src/print_util.c src/token_util2.c src/exec_multi.c \
	src/util2.c src/util3.c src/quote_util.c src/exec_single.c src/exec_util.c \
	src/built_in_util.c src/pipe_fds.c src/env_util.c
SRC = $(M_SRC)
OBJ = $(SRC:.c=.o)
READLINE = -L./lib/readline/lib -I./lib/readline/include/readline -lreadline 
DIR     = $(shell echo $(PWD))
RM = rm -rf
RL = ./lib/readline/lib/libreadline.a


all: $(NAME)

$(NAME): $(RL) $(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(READLINE)

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