/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:51:09 by rghouzra          #+#    #+#             */
/*   Updated: 2023/06/15 11:53:42 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DQ 34
#define SQ 39

int			helper_visualizer(const char *s, char c);

static int	str_in_sep(char cs, char c)
{
	if (cs == c || cs == '\t')
		return (1);
	return (0);
}

// typedef struct s_alphasplit
// {
// 	size_t	i;
// 	size_t	str_count;
// 	char	**strings;
// 	int		quotes_counter;
// 	char	cs;
// 	size_t	length;
// 	char	*word;
// 	char	c;

// }			t_alphasplit;

static char	*ft_words(const char *s, char sep)
{
	t_alphasplit	x;

	x.length = 0;
	x.i = 0;
	if (*(s + x.length) == DQ || *(s + x.length) == SQ)
	{
		x.c = *(s + x.length);
		if (helper_visualizer(s, x.c) == 1)
			x.length = 0;
		else
		{
			if (*(s + x.length) && *(s + x.length) == x.c)
				x.length++;
			while (*(s + x.length) && *(s + x.length) != x.c)
				x.length++;
			if (*(s + x.length) && *(s + x.length) == x.c)
				x.length++;
		}
	}
	else
	{
		while (*(s + x.length) && (!str_in_sep(*(s + x.length), sep) && (*(s
						+ x.length) != DQ && *(s + x.length) != SQ)))
			x.length++;
	}
	x.word = (char *)ft_malloc((x.length + 1) * sizeof(char));
	return (ft_strlcpy(x.word, s, x.length + 1), x.word);
}

int	helper_visualizer(const char *s, char c)
{
	int	checker;

	checker = 0;
	if (*s && *s == c)
	{
		checker = 1;
		s++;
	}
	while (*s && *s != c)
	{
		return (0);
		s++;
	}
	if (*s && *s == c)
	{
		checker = 1;
		s++;
	}
	return (checker);
}

static int	ft_second_handle_quote(const char *s, char c)
{
	int	j;

	j = 0;
	if (s[j] && s[j] == c)
		j++;
	while (s[j] && s[j] != c)
		j++;
	if (s[j] && s[j] == c)
		j++;
	return (j);
}

static char	*to_strings(char **strings, char const *s, char c)
{
	size_t	i;
	char	cs;

	i = 0;
	while (*s)
	{
		while (str_in_sep(*s, c) && *s)
			s++;
		if (*s)
		{
			strings[i++] = ft_words(s, c);
			if (!(strings + i))
				return (ft_free(strings));
		}
		if (*s == DQ || *s == SQ)
		{
			cs = *s;
			s = s + ft_second_handle_quote(s, cs);
			if (*s == 0)
				break ;
		}
		else
		{
			while ((!str_in_sep(*s, c)) && *s && *s != DQ && *s != SQ)
				s++;
		}
	}
	return (strings[i] = 0, NULL);
}

static int	ft_handle_quote(const char *s, size_t *i, char c, int quotes_ctr)
{
	int	j;
	int	check_quote_ctr;

	quotes_ctr = 0;
	check_quote_ctr = 0;
	j = *i;
	if (s[j] && s[j] == c)
	{
		quotes_ctr++;
		j++;
	}
	while (s[j] && s[j] != c)
		j++;
	if (s[j] && s[j] == c)
	{
		check_quote_ctr++;
		j++;
	}
	if (!quotes_ctr || !check_quote_ctr || (quotes_ctr % 2 == 0
			+ check_quote_ctr % 2 == 0) % 2 != 0)
		return (0);
	*i = j;
	return (1);
}

char	**ft_alphasplit2(char const *s, char c)
{
	t_alphasplit	x;

	x.str_count = 0;
	x.i = 0;
	while (1)
	{
		x.quotes_counter = 0;
		while (str_in_sep(*(s + x.i), c) && *(s + x.i))
			x.i++;
		if (*(s + x.i) == '\0')
			break ;
		x.str_count++;
		if (s[x.i] == DQ || s[x.i] == SQ)
		{
			x.cs = s[x.i];
			if (!ft_handle_quote(s, &x.i, x.cs, x.quotes_counter))
				return (printf("inclosed quotes\n"), NULL);
			if (s[x.i] == 0)
				break ;
		}
		else
		{
			while (!str_in_sep(*(s + x.i), c) && *(s + x.i) && s[x.i] != DQ
				&& s[x.i] != SQ)
				x.i++;
		}
	}
	x.strings = (char **)ft_malloc((x.str_count + 1) * sizeof(char *));
	return (to_strings(x.strings, s, c), x.strings);
}