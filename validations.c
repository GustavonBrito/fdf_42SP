/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:01:45 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/08 00:06:57 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/err_messages.h"
#include "includes/fdf.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"
#include "minilibx/mlx.h"

int	validate_map_values(char *path_file)
{
	char	*buffer;
	char	**split;
	int		fd;
	int		i;

	fd = open(path_file, O_RDONLY);
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
				return ((ft_free_split(split, i)), (free(buffer)), (-1));
			i++;
		}
		ft_free_split(split, i);
		free(buffer);
	}
	return (1);
}

int	validate_map_structure(int fd)
{
	char	**split;
	char	*buffer;
	int		i;
	int		first_line;

	first_line = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		split = ft_split(buffer, ' ');
		i = 0;
		while (split[i])
			i++;
		if (first_line == 0)
			first_line = i;
		else if (first_line != i)
			return ((ft_free_split(split, i)), (free(buffer)), (-1));
		ft_free_split(split, i);
		free(buffer);
	}
	return (1);
}

int	check_file_permissions(char *path_file)
{
	int	fd;

	fd = 0;
	fd = open(path_file, O_RDONLY);
	if (fd == -1)
	{
		exit(EXIT_FAILURE);
		close(fd);
		return (-1);
	}
	else
		return (fd);
	return (-1);
}

int	validate_file_extension(char *path_file)
{
	int	len;
	int	ext_len;

	ext_len = ft_strlen(".fdf");
	len = ft_strlen(path_file);
	if (len < ext_len)
		return (-1);
	if (ft_strncmp(&path_file[len - ext_len], ".fdf", ext_len) == 0)
		return (1);
	return (1);
}

int	init_validations(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc == 2)
	{
		if (validate_file_extension(argv[1]) == 1)
			ft_printf("Extensao correta\n");
		fd = check_file_permissions(argv[1]);
		if (fd >= 1)
			ft_printf("Permissao correta\n");
		else
			return (-1);
		if (validate_map_structure(fd) == 1)
			ft_printf("Estrutura ok\n");
		if (validate_map_values(argv[1]) == 1)
			ft_printf("Valores do mapa estao ok\n");
	}
	close(fd);
	return (0);
}
