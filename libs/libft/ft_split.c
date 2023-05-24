/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:12:22 by rghouzra          #+#    #+#             */
/*   Updated: 2023/03/01 10:23:01 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	str_in_sep(char cs, char c)
{
	if (cs == c)
		return (1);
	return (0);
}

static char	*ft_words(const char *s, char sep)
{
	size_t	i;
	size_t	length;
	char	*word;

	length = 0;
	i = 0;
	while (*(s + length) && !str_in_sep(*(s + length), sep))
		length++;
	word = (char *)ft_malloc((length + 1) * sizeof(char));
	while (i < length)
	{
		*(word + i) = *(s + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}

static char	*to_strings(char **strings, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (str_in_sep(*s, c) && *s)
			s++;
		if (*s)
		{
			strings[i] = ft_words(s, c);
			if (!strings[i++])
				return (ft_free(strings), NULL);
			s++;
		}
		while (!str_in_sep(*s, c) && *s)
			s++;
	}
	return (strings[i] = 0, NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	str_count;
	char	**strings;

	str_count = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (1)
	{
		while (str_in_sep(*(s + i), c) && *(s + i))
			i++;
		if (*(s + i) == '\0')
			break ;
		str_count++;
		while (!str_in_sep(*(s + i), c) && *(s + i))
			i++;
	}
	strings = (char **)ft_malloc((str_count + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	return (to_strings(strings, s, c), strings);
}
