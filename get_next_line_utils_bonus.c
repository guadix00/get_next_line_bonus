/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:45:22 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/28 14:48:25 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*memory;
	size_t	i;					

	i = 0;
	memory = malloc(num * size);
	if (!memory)
		return (NULL);
	while (i < (num * size))
	{
		((char *)memory)[i] = '\0';
		i++;
	}
	return (memory);
}

int	strchrpos(char *str, int find, int flag)
{
	int	i;

	i = 0;
	if (!str)
		return (NOT_FOUND);
	while (str[i])
	{
		if (str[i] == (char)find)
			return (i);
		i++;
	}
	if (!str[i] && flag == FALSE)
		return (i);
	return (ERROR);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
