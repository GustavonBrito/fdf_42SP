/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:18:08 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/10 21:21:10 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
char	*ft_strdup_gnl(const char *s);
char	*get_next_line(int fd);

#endif