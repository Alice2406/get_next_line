/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:44:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/10 15:01:08 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	char *buffer;
	char *chaine;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, &buffer, BUFFER_SIZE)
	while (*buffer)
	{
		if(*buffer == '\n')
		{
			

