/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:08:52 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/08 17:53:18 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int			fd;
	const char	*pathname = "/home/tmagoudi/Documents/Projects/GNL/text.txt";
	const char	*pathname_1 = "/home/tmagoudi/Documents/Projects/GNL/text_1.txt";
	const char	*pathname_2 = "/home/tmagoudi/Documents/Projects/GNL/text_2.txt";
	char		*buffer;

	fd = open(pathname, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	buffer = (NULL);
	fd = close(fd);
	if (fd == -1)
	{
		printf("\nError the file didn't closed correctly\n");
		return (0);
	}
	printf("The file closed without error \n");
	return (1);
}
