/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:01:45 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/04 23:49:04 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/libft.h"
#include "libft/headers/get_next_line.h"
#include "minilibx/mlx.h"

int	validate_map_structure(int fd)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer != NULL)
			ft_printf("%s", buffer);
		else
			break ;
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
		return (0);
	if (ft_strncmp(&path_file[len - ext_len], ".fdf", ext_len) == 0)
		return (1);
	return (0);
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
			ft_printf("Estrutura do mapa esta ok\n");
	}
	return (0);
}
