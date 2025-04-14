/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:09:18 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/13 18:15:14 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

void		free_buffer_gnl(char *buffer, int fd);
int			validate_element(char *token);
void		ft_free_split(char **array, char *buffer);

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
