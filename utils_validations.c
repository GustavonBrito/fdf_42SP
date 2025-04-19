/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:31:58 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 11:59:44 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_words_spaces(char *line);
void	free_buffer_gnl(char *buffer, int fd);
int		validate_element(const char *token);
void	ft_free_split(char **array, char *buffer);

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

int	validate_element(const char *token)
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

int	count_words_spaces(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] && line[i] != '\n')
		{
			count++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
		}
		i++;
	}
	return (count);
}
