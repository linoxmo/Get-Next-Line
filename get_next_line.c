/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:43:26 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/06 12:22:07 by tmagoudi         ###   ########.fr       */
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

/*char	*ft_read(char *buffer)
{
	

}
*/

char	*get_next_line(int fd)
{
	char	*buffer;
	int	nb_read;
	int	count;
	static	char	*result;
	char	*temp;

	buffer = malloc(sizeof(char) * (20 + 1));
	result = ft_strndup("",1);
	nb_read = -1;
	count = 0;
	while (nb_read) 
	{
		nb_read = read(fd, buffer, 20); 
		buffer[nb_read] = '\0';
		temp = ft_strjoin(result, buffer);
		free(result);
		result  =  temp;
		if (ft_strchr(buffer, '\n'))
		{	
			count++;
			printf("on passe le break apres %d iteration\n",count);	
			break;
		}
		if (nb_read == -1)
			return (free(result), free(buffer), NULL);
	}
	temp = ft_strndup(result, ft_strchr(result, '\n') - result); 
	free(buffer);
	return (temp);
}
