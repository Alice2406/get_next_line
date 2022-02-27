/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:52:28 by aniezgod          #+#    #+#             */
/*   Updated: 2022/02/27 16:24:34 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*chaine;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	chaine = (char *)malloc(sizeof(*s1) * (i + j + 1));
	if (!chaine)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		chaine[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		chaine[j + i] = s2[j];
		j++;
	}
	chaine[j + i] = '\0';
	return (free(s1), chaine);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*chaine;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len < (size_t)ft_strlen(s))
		chaine = (char *)malloc(sizeof(*s) * (len + 1));
	else
		chaine = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!chaine)
		return (0);
	while (i != start && s[i])
		i++;
	while (s[i] && j < len)
		chaine[j++] = s[i++];
	if (i >= start - 1 || !s)
		free(s);
	if (j == 0)
		return (free(chaine), NULL);
	chaine[j] = '\0';
	return (chaine);
}

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
	char		*buffer;
	int			i;
	static char	*chaine[1024];
	char		*line_read;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	buffer = malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while ((i > 0) && (line(chaine[fd], 0) == -1
			|| ft_strlen(chaine[fd]) - line(chaine[fd], 0) == 0))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			break ;
		buffer[i] = '\0';
		chaine[fd] = ft_strjoin(chaine[fd], buffer);
	}
	line_read = ft_substr(chaine[fd], 0, (line(chaine[fd], 0) + 1));
	i = line(chaine[fd], 0) + 1;
	chaine[fd] = ft_substr(chaine[fd], i, (ft_strlen(chaine[fd]) - i));
	return (free(buffer), line_read);
}
