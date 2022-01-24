/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:44:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/24 16:01:34 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	point_end_string(char *buffer, int j)
{
	int i;

	i = j;
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
	char *chaine;
	int j;
	
	j = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i = read(fd, buffer, BUFFER_SIZE))
	{
		if (i <= 0)
			break;
		buffer[i] = '\0';
		while (point_end_string(buffer, j) != -1)
		{
			chaine = ft_substr(buffer, j, point_end_string(buffer, j));
			printf("%s\n", chaine);
			j = point_end_string(buffer, j);
		}
	}
	return(NULL);
}

int main(int argc, char **argv)
{
	int fd;

	if(argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	return (0);
}
