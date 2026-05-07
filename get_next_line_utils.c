/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:36:57 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/07 16:39:20 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	l_1;
	size_t	l_2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	l_1 = ft_strlen(s1);
	l_2 = ft_strlen(s2);
	if (l_1 > ((size_t)-1) - l_2 - 1)
		return (NULL);
	new = malloc(l_1 + l_2 + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char    *ft_strdup(const char *s)
{
        size_t  i;
        char    *dst;

        if (!s)
                return (NULL);
        dst = malloc(ft_strlen(s) + 1);
        if (!dst)
                return (NULL);
        i = 0;
        while (s[i])
        {
                dst[i] = s[i];
                i++;
        }
        dst[i] = '\0';
        return (dst);
}

int ft_strchr(const char *s, int c)
{
	int	count;

	if (!s)
		return (-1);
	count = 0;
	while (*s)
	{
		if (*s == (char)c)
			return (count);
		s++;
		count++;
	}
	if (*s == (char)c)
		return (count);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (s[start] && i < len)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
