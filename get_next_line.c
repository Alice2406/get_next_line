/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:44:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/02/17 15:50:08 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	line(char *buffer, int i)
{
	if (!buffer)
		return (-1);
	while (1)
	{
		if(buffer[i] == '\n' || buffer[i] == 0)
			return (i);
		i++;
	}
	return(-1);
}

int	new_line(char *buffer)
{
	int i = 0;
	if (!buffer)
		return (0);
	while(buffer[i])
	{
			if(buffer[i] == '\n')
					return (1);
			i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	char *buffer;
	int i;
	static char *chaine;
	char *line_read;
	int j;
	
	j = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while ((i > 0) && new_line(chaine) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		chaine = ft_strjoin(chaine, buffer);
	}
	line_read = ft_substr(chaine, 0, (line(chaine, j) + 1));
	//printf("line = %s\n", line_read);
	j = line(chaine, j) + 1;
	//printf("j = %d\n", j);
	chaine = ft_substr(chaine, j, (ft_strlen(chaine) - j));
	//printf("save = %s\n\n\n\n\n\n", chaine);
	return(line_read);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	int fd;
	char *line;
	int i = 20;

	if(argc < 2)
		return(1);
	fd = open (argv[1], O_RDONLY);
	line = get_next_line(fd);
	while(i--)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/
