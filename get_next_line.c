/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:43:26 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/06 17:44:50 by tmagoudi         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*buffer;
	int			nb_read;
	static char	*result;
	char		*temp;

	buffer = malloc(sizeof(char) * (5000 + 1));
	if (!result)
		result = ft_strndup("", 1);
	nb_read = -1;
	while (nb_read)
	{
		nb_read = read(fd, buffer, 5000);
		if (nb_read == -1)
			return (free(result), free(buffer), NULL);
		buffer[nb_read] = '\0';
		result = ft_realloc_join(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	temp = ft_strndup(result, ft_strchr(result, '\n') - result + 1);
	result = ft_realloc_substr(result, ft_strchr(result, '\n') - result + 1,
			ft_strlen(result) - ft_strlen(temp));
	free(buffer);
	return (temp);
}
