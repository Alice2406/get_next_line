/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:52:28 by aniezgod          #+#    #+#             */
/*   Updated: 2022/02/21 15:52:43 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	line(char *buffer, int i)
{
	if (!buffer)
		return (-1);
	while (1)
	{
		if (buffer[i] == '\n' || buffer[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			i;
	static char	*chaine;
	char		*line_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 1;
	while ((i > 0) && (line(chaine, 0) == -1
			|| ft_strlen(chaine) - line(chaine, 0) == 0))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			break ;
		buffer[i] = '\0';
		chaine = ft_strjoin(chaine, buffer);
	}
	line_read = ft_substr(chaine, 0, (line(chaine, 0) + 1));
	i = line(chaine, 0) + 1;
	chaine = ft_substr(chaine, i, (ft_strlen(chaine) - i));
	return (line_read);
}
