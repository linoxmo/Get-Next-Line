/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:59:50 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/06 17:27:17 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char *	get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char const *s1, size_t n);
char    *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char*	ft_realloc_join(char *s1, char *s2);
#endif
