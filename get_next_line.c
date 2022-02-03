/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:44:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/02/03 15:12:03 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	line(char *buffer, int i)
{
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if(buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return(-1);
}

char *get_next_line(int fd)
{
	char *buffer;
	int i;
	static char *chaine;
	char *line_read;
	int j;
	int k;
	
	j = 0;
	k = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((i = read(fd, buffer, BUFFER_SIZE)) && line(chaine, j) != -1)
	{
		if (i <= 0)
			break;
		buffer[i] = '\0';
		chaine = ft_strjoin(chaine, buffer);
		printf("%s\n", chaine);
	}
	j = line(buffer, j) + 1;
	line_read = ft_substr(buffer, k, (line(buffer, j) - k));
	k = j;
	chaine = ft_substr(buffer, k, (line(buffer, j) - k));
	return(line_read);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	int fd;
	char *line;

	if(argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
