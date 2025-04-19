/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:24:22 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 13:24:24 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			validate_map_values(char *file_path);
int			validate_map_structure(int fd);
int			check_file_permissions(char *file_path);
int			validate_file_extension(char *file_path);
int			init_validations(int argc, char **argv);

int	init_validations(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc == 2)
	{
		if (validate_file_extension(argv[1]) == -1)
			return (-1);
		fd = check_file_permissions(argv[1]);
		if (fd < 1)
			return (-1);
		if (validate_map_structure(fd) == -1)
			return (-1);
		if (validate_map_values(argv[1]) == -1)
			return (-1);
		close(fd);
	}
	return (1);
}

int	validate_map_values(char *file_path)
{
	char	*buffer;
	char	**split;
	int		fd;
	int		i;

	fd = open(file_path, O_RDONLY);
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		split = ft_split(buffer, ' ');
		i = 0;
		while (split[i])
		{
			if (validate_element(split[i]) == -1)
				return ((free_buffer_gnl(buffer, fd)),
					(ft_free_split(split, NULL)), (-1));
			i++;
		}
		ft_free_split(split, buffer);
	}
	close(fd);
	return (1);
}

int	validate_map_structure(int fd)
{
	char	*buffer;
	int		i;
	int		first_line;

	first_line = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		i = count_words_spaces(buffer);
		if (first_line == 0)
			first_line = i;
		else if (first_line != i)
			return (free_buffer_gnl(buffer, fd), (-1));
		free(buffer);
	}
	return (1);
}

int	check_file_permissions(char *file_path)
{
	int	fd;

	fd = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	else
		return (fd);
	return (-1);
}

int	validate_file_extension(char *file_path)
{
	int	len;
	int	ext_len;

	ext_len = ft_strlen(".fdf");
	len = ft_strlen(file_path);
	if (len < ext_len)
		return (-1);
	if (ft_strncmp(&file_path[len - ext_len], ".fdf", ext_len) == 0)
		return (1);
	return (-1);
}
