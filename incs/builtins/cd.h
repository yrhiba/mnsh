/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:12:48 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/16 11:08:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
	cd change directory
	only accept relative of absolut path
*/
int	cd(int ac, char **av, int mode);

#endif
