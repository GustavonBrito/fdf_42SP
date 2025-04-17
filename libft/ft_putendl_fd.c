/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:33:20 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/17 12:33:23 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	a;

	a = 0;
	if (fd < 0)
		fd = -fd;
	if (s == (void *)0)
		return ;
	while (s[a])
	{
		write(fd, &s[a], 1);
		a++;
	}
	write(fd, "\n", 1);
}
