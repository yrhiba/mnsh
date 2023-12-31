/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:16:32 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/20 15:32:27 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

static int	to_expand(char *s, char **new, int i)
{
	char	*key;
	int		j;

	key = (char *)0;
	j = i;
	while (is_valid_char(s[i], ((i)-j)))
	{
		if (my_string_append_char(&key, s[i]) == -1)
			exit(EXIT_FAILURE);
		i++;
	}
	if (i == j)
	{
		if (s[i] == '?')
		{
			key = ft_itoa(get_the_exitstatus());
			if (!key)
				exit(EXIT_FAILURE);
			if (my_string_append(new, key) == -1)
				exit(EXIT_FAILURE);
			return (free(key),key = NULL, ++i);
		}
		if (my_string_append_char(new, '$') == -1)
			exit(EXIT_FAILURE);
		return (i);
	}
	else if (append_value(new, key) == -1)
		exit(EXIT_FAILURE);
	return (free(key), i);
}

char	*expand(char **s)
{
	char	*new;
	int		i;

	new = (char *)0;
	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '$')
			i = to_expand(*s, &new, i + 1);
		else
		{
			if (my_string_append_char(&new, (*s)[i]) == -1)
				exit(EXIT_FAILURE);
			i++;
		}
	}
	free(*s);
	*s = new;
	return (*s);
}
