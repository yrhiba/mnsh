/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:45:36 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 04:29:02 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include "libmystr.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/*
	echo		"print args to stdout whit newline"
	echo -n		"print args to stdout whitout newline"
*/

typedef struct s_echo
{
	char	*buff;
	int		n;
	int		size;
	int		flag;

}		t_echo;

void		echo(int ac, char **av, int mode);

#endif
