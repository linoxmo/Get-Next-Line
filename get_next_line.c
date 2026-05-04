/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:43:26 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/04 19:46:15 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


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

char	*get_next_line(int fd)
{
	char	*buffer;
	int	nb_read;
	int	count;
	char	*result;

	buffer = malloc(sizeof(char) * (20 + 1));
	result = malloc(sizeof(char) * 1);
	nb_read = -1;
	count = 0;
	while (nb_read && count != 2) 
	{
		nb_read = read(fd, buffer, 20); 
		buffer  =  ft_check_nl(buffer);
		if (nb_read == -1)
		{
			write(1, "Lecture Error", 14);
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		if(nb_read)
			printf("La string lu est : \n%s\n", buffer);
		count++;
	}
	return (buffer);
}
