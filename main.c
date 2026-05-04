/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:08:52 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/04 16:07:30 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	const	char*	pathname = "/home/tmagoudi/Documents/Projects/GNL/text.txt";
	char *	buffer;

	fd = open(pathname, O_RDONLY);
	buffer = get_next_line(fd);
	fd = close(fd);
	if (fd == -1)
	{
		printf("\nError the file didn't closed correctly\n");
		return(0);
	}
	printf("The file closed without error \n");
	return (1);
}
