/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:34:18 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/21 21:40:21 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	execute_with_fork(char **cmnds, t_io x)
{
	pid_t	pid;

	if (ifbuiltinbreak(cmnds, NO_EXIT) == EXIT_SUCCESS)
		return ;
	pid = ft_fork();
	if (!pid)
	{
		if (x.be_dupped == -1)
			show_error(strerror(errno), 1);
		if (x.stream != -2)
			dup2(x.be_dupped, x.stream);
		execute(cmnds + x.increment);
	}
	else
		waitpid(pid, &(g_mnsh->exit_status), 0);
	ft_free(cmnds);
}

void	pipeline(t_ast *tree, t_io x)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (!tree)
		return ;
	ft_pipe(fd);
	pid1 = ft_fork();
	if (pid1 == 0)
	{
		dup_close(fd, x.output, 1);
		eval_tree(tree->left, 1, x);
		exit(0);
	}
	pid2 = ft_fork();
	if (pid2 == 0)
	{
		dup_close(fd, x.input, 0);
		eval_tree(tree->right, 1, x);
		exit(0);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, &(g_mnsh->exit_status), 0);
	waitpid(pid2, &(g_mnsh->exit_status), 0);
}

void	eval_logical_op(t_ast *tree, t_io x)
{
	if (tree->type == AND_CMD_CHAIN)
	{
		eval_tree(tree->left, 0, x);
		if (!g_mnsh->exit_status)
			eval_tree(tree->right, 0, x);
	}
	if (tree->type == OR_CMD_CHAIN)
	{
		eval_tree(tree->left, 0, x);
		if (g_mnsh->exit_status)
			eval_tree(tree->right, 0, x);
	}
}

void	eval_other_type(t_ast *tree, t_io x, int is_child)
{
	char	**cmnds;

	if (tree->type == WORD)
	{
		cmnds = contrui_cmnds(tree);
		if (is_child)
			execute(cmnds);
		else
			execute_with_fork(cmnds, x);
	}
	else
		eval_logical_op(tree, x);
}

void	eval_tree(t_ast *tree, int is_child, t_io x)
{
	if (!tree)
		return ;
	expand_term(tree);
	expand_wildcard(tree);
	if (tree->type == redir_o)
		handle_rediro(tree, x, is_child);
	if (tree->type == redir_i)
		handle_rediri(tree, x, is_child);
	if (tree->type == append_o)
		handle_append(tree, x, is_child);
	if (tree->type == heredoc_i)
		handle_heredoc(tree, x, is_child);
	if (tree->type == PIPE)
		pipeline(tree, x);
	else
		eval_other_type(tree, x, is_child);
}
