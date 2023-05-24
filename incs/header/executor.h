#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "header.h"

typedef struct s_exec
{
	int		i;
	char	**paths;
	char	*cmd;
}			t_exec;

typedef struct s_io
{
    int input;
    int output;
	int be_dupped;
	int	stream;
	int	increment;
}			t_io;

typedef struct s_openpar
{
	int flags;
	int permissions;
	int stream;
}t_openpar;

char		*execute(char *env, char **cmnds);
char		*find_paths(char **env);
void		eval_tree(t_ast *tree, char *env, int is_child, t_io x);
int			check_access(char *path, int which);
char		*find_path(char *cmd, char **paths);
void		handle_rediro(t_ast *tree, t_io x, int is_child, char *env);
void		handle_rediri(t_ast *tree, t_io x, int is_child, char *env);
void get_virual_operands(char *operands, t_openpar x, int is_running, char *env);
void handle_append(t_ast *tree, t_io x, int is_child, char *env);

#endif