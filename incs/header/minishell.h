/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:25:12 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 13:05:23 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "header.h"

# ifdef __linux__
#  include <sys/types.h>
#  include <dirent.h>
#  include <readline/history.h>
#  include <sys/wait.h>
#  include <readline/readline.h>
# elif defined(__APPLE__) && defined(__MACH__)
#  include "readline/history.h"
#  include "readline/readline.h"
#  include <dirent.h>
# endif

# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>

#endif
