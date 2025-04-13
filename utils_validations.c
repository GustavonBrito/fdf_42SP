/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:59:56 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/13 16:05:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

void	ft_free_split(char **array, char *buffer)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	if (buffer)
		return (free(array), free(buffer));
	else
		return (free(array));
}

int	validate_element(char *token)
{
	int	i;

	i = 0;
	while (ft_isdigit(token[i]) == 1 || token[i] == '-')
		i++;
	if (token[i] != ',' && token[i] != '\0' && token[i] != '\n')
		return (-1);
	if (token[i] == ',')
	{
		if (token[i + 1] != '0' || token[i + 2] != 'x')
			return (-1);
	}
	else if (token[i] == '\n')
		return (1);
	return (1);
}

void	free_buffer_gnl(char *buffer, int fd)
{
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
	}
}
