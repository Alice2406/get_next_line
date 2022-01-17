/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:44:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/17 10:57:18 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char *run_string(char *buffer)
{
	char *chaine;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			chaine = ft_substr(buffer, j, i);
			j = i;
		}
		i++;
	}
}

char *get_next_line(int fd)
{
	char *buffer;
	char *chaine;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, &buffer, BUFFER_SIZE) > 0)
	{
		run_string(buffer);

