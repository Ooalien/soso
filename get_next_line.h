/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:26:55 by abayar            #+#    #+#             */
/*   Updated: 2021/11/23 23:52:38 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);

#endif
