/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:06:57 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 10:13:45 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "header.h"
# include <stdbool.h>

typedef struct s_delim_expand
{
	int		i;
	char	**lines;
	int		j;
	int		dollar;
	char	c;
	int		flag;
}t_delim_expand;

typedef struct s_read_heredoc
{
	char	*line;
	int		fd;
	char	*name;
	int		flag_expansion;
	char	*ptr;
}t_read_heredoc;

typedef struct s_queue
{
	void			*content;
	t_tokentype		type;
	t_list			*next_word;
	struct s_queue	*head;
	struct s_queue	*next;
	struct s_queue	*tail;

}					t_queue;

typedef struct s_poped
{
	t_tokentype		type;
	void			*content;
	t_list			*next_word;
}					t_poped;

bool				enqueue(t_queue **q, char *value, enum TokenType type,
						t_list *next_word);

int					get_token_priority(t_list *q);
bool				dequeue(t_queue **q);
void				init_queue(t_queue *q);
t_poped				pop(t_list **p);
bool				push(t_list **p, void *value, t_tokentype type,
						t_list *next_word);
int					peek(t_list *s);
void				ft_tokencleaner(t_list **token);
void				tree_cleaner(t_ast **tree);

char				*getcmdfullpath(char *cmd);
void				signal_utils(void);
void				export_sort(void);
int					ifbuiltinbreak(char **cmnds, int mode);
char				**contrui_env(void);
int					exit_status(int status, int mode);

char				**contrui_cmnds(t_ast *tree);

void				ft_clean_nextword(t_list **token);

int					get_arg_pos(t_my_list *it, char *arg);

char				*generate_filename(void);
char				*read_heredoc(char *delemiter);

int					remove_quotes(char **s);
void				free_string(void **arg);
int					get_the_exitstatus(void);

char				*remove_quotes_2(char **line);
t_my_list			*pattern_matching(char *patter);
#endif
