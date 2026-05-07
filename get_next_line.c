/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:43:26 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/07 16:21:29 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_realloc_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

char	*ft_realloc_substr(char *s, unsigned int start, size_t len)
{
	char	*temp;

	temp = ft_substr(s, start, len);
	free(s);
	return (temp);
}

char	*ft_read(int fd, char *result)
{
	char	*buffer;
	int	nb_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = -1;
	while (nb_read)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (free(result), free(buffer), NULL);
		buffer[nb_read] = '\0';
		result = ft_realloc_join(result, buffer);
		if (ft_strchr(buffer, '\n') > 0)
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*temp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!result)
		result = ft_strndup("", 1);
	result = ft_read(fd, result);
	if (!result || !*result)
		return (free(result), NULL);
	int i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	temp = ft_strndup(result, i + 1  
			+ (ft_strchr(result, '\n') != -1));
	result = ft_realloc_substr(result, i + 1
			+ (ft_strchr(result, '\n') != -1), ft_strlen(result)
			- ft_strlen(temp));
	return (temp);
}
