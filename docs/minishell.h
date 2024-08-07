#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include "sys/wait.h"
# include "sys/types.h"

# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_RESET "\x1b[0m"

# define ENV_LIMIT 1000

# define ERR_NO_SUCH_FİLE_OR_DIRECTORY 127
# define ERR_COMMAND_NOT_FOUND 127
# define ERR_IS_A_DIRECTORY 126
# define ERR_PERMİSSİON_DENIED 126
# define ERR_TOO_MANY_ARGS 126
# define ERR_NOT_SET 1
# define ERR_NOT_FOUND 1
# define ERR_NOT_VALID 1

# define ENDL "\n"

# define M_ERR_UNKWN "unkown error"
# define M_ERR_CMD_NOT_FOUND "command not found"
# define M_ERR_HOME_NOT_SET "HOME not set"
# define M_ERR_OLDPWD_NOT_SET "OLDPWD not set"
# define M_ERR_INVALID_ARG "invalid argument"
# define M_ERR_NO_SUCH_FILE_OR_DIRECTORY "No such file or directory"
# define M_ERR_IS_A_DIRECTORY "is a directory"
# define M_ERR_PERMİSSİON_DENIED "Permission denied"
# define M_ERR_TOO_MANY_ARGS "too many arguments"
# define M_ERR_NOT_VALID_CTX "not valid context"
# define M_ERR_SYNTAX_ERROR "syntax error"
# define M_ERR_MISS_QUOTE "unexpected quote `'', `\"'"

# define PROMPT " : minishell$ "

# define ENV_PATH "PATH"

typedef bool t_bool;

typedef struct s_token
{
	char	*data;
	int		type;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

typedef struct s_data
{
	t_token	**token_ar;
	char	*prompt;
	char	**envp;
	char	**av;
	char	*mini_prompt;
	int		status;
	int		cmd_ct;
	int		pid;
	int		err;
}				t_data;

#endif