/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:16:13 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 10:25:52 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "header.h"

# define EXEC 111
# define LEFT 666
# define RIGHT 999
# define PARENT 0

typedef struct s_exec
{
	int		i;
	char	**paths;
	char	*cmd;
}			t_exec;

typedef struct s_io
{
	int		rediro_prev;
	int		rediri_prev;
	int		input;
	int		output;
	int		be_dupped;
	int		stream;
	int		increment;
}			t_io;

typedef struct s_openpar
{
	int		flags;
	int		permissions;
	int		stream;
}			t_openpar;

void		handle_heredoc(t_ast *tree, t_io x, int is_child);
char		*execute(char **cmnds);
void		eval_tree(t_ast *tree, int is_child, t_io x);
int			check_access(char *path, int which);
void		handle_rediro(t_ast *tree, t_io x, int is_child);
int			ft_redir_optimizer(t_ast *tree);
void		handle_rediri(t_ast *tree, t_io x, int is_child);
char		**check_return_gev(t_ast *tree);
void		get_virual_operands(char *operands, t_openpar x, int is_running,
				t_ast *tree);
void		handle_append(t_ast *tree, t_io x, int is_child);
char		**convert_to_table(t_my_list *list);
t_my_list	*get_expanded_values(t_ast *tree);
void		dup_close(int *fd, int new_fd, int index);
void		execute_with_fork(char **cmnds, t_io x);
#endif
