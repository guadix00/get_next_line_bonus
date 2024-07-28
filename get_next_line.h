/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:27:57 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/28 15:40:42 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define NOT_FOUND -1
# define ERROR -1
# define TRUE	1
# define FALSE	0

# include <stdlib.h>
# include <unistd.h>

void		*ft_calloc(size_t num, size_t size);
int			strchrpos(char *str, int c, int flag);
size_t		ft_strlen(char *str);
char		*strjoin(char *s1, char *s2);

char		*protect_join(char *buffer, char *reading);
char		*get_next_line(int fd);
char		*read_line(int fd, char *buffer);
char		*get_line(char *buffer);
char		*update_buffer(char *buffer, char *line);
char		*ft_free(char **str);	
#endif
