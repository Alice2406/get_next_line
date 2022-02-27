/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:50:39 by aniezgod          #+#    #+#             */
/*   Updated: 2022/02/27 16:45:26 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

int		do_smth(int fd);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
int		line(char *buffer, int i);

#endif
