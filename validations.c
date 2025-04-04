/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:01:45 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/04 00:08:30 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/headers/libft.h"
#include "libft/headers/ft_printf.h"
#include "includes/fdf.h"

// fd = open(argv[1], O_RDONLY);
// if (fd == -1)
// 	exit(EXIT_FAILURE);
// else
// 	ft_printf("passou");
// close(fd);

int validate_file_extension(char *path_file)
{
	int i;
	
	i = 0;
	while (path_file[i])
	{
		if (path_file[i] == '.' && ft_strncmp(&path_file[i], ".fdf", ft_strlen(path_file)) == 0)
		{
			ft_printf("aaaaadasd");
		}
		i++;
	}
	return (0);
}

int init_validations(int argc, char **argv)
{
	if (argc == 2)
	{
		validate_file_extension(argv[1]);
	}
	return (0);
}