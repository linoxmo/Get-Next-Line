/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:43:26 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/06 17:27:47 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
char	*ft_check_nl(char *buffer)
{
	int		count;
	char	*result;

	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	result = malloc((count + 1) * sizeof(char));
	count = 0;
	while (buffer[count] && buffer[count] !='\n')
	{
		result[count] = buffer[count];
		count++;	
	}
	result[count] = '\0';
	return (result);
}
*/

char	*ft_realloc_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);

	return (temp);

}

char	*get_next_line(int fd)
{
	char	*buffer;
	int	nb_read;
	static char	*result;
	char	*temp;
	char	*temp_1;

	buffer = malloc(sizeof(char) * (5000+1));
	if(!result)
		result = ft_strndup("",1);
	nb_read = -1;
	while (nb_read) 
	{
		nb_read = read(fd, buffer, 5000); 
		if (nb_read == -1)
			break;
		buffer[nb_read] = '\0';
		//temp = ft_strjoin(result, buffer);
		//free(result);
		result  =  ft_realloc_join(result,buffer);
		if (ft_strchr(buffer, '\n'))
			break;
		if (nb_read == -1)
			return (free(result), free(buffer), NULL);
	}
	temp = ft_strndup(result, ft_strchr(result, '\n') - result + 1); 
	temp_1= ft_substr(result,  ft_strchr(result, '\n') - result + 1 , ft_strlen(result) - ft_strlen(temp));
	free(result);
	result  = temp_1;
	free(buffer);
	return (temp);
}
