/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:50:02 by aniezgod          #+#    #+#             */
/*   Updated: 2022/02/03 15:06:44 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chaine;
	size_t	i;
	size_t	j;

//	if (!s1 || !s2)
//		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	chaine = (char *)malloc(sizeof(*s1) * (i + j + 1));
	if (!chaine)
		return (NULL);
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
	return (chaine);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	{
		chaine[j] = s[i];
		j++;
		i++;
	}
	chaine[j] = '\0';
	return (chaine);
}

/*
 Je suis un test
 mai
 
 is
 balek
 frero

	TANTQUE(i > 1 && pas de \n dans la static)
	{
		i = read
		buffer[i] = 0
		static = strjoin(static, buffer)
	}
	line = fonction qui return jusqua \n;
	static = fonction qui return tout apres \n;
	return (line);

*/
