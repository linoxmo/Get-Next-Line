/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:43:26 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/04 16:11:16 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>







char	*get_next_line(int fd)
{
	char	*buffer;
	int	nb_read;
	int	count;

	buffer = malloc(sizeof(char) * (20 + 1));
	nb_read = -1;
	count = 0;
	while (nb_read && count != 2) 
	{
		nb_read = read(fd, buffer, 20); 
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
