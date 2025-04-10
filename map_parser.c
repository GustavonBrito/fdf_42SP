/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:31:29 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/10 01:18:21 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/err_messages.h"
#include "includes/fdf.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"
#include "minilibx/mlx.h"

int save_values_to_struct(char *path_file)
{
	char *buffer;
	char **split;
	int fd;
	int count;
	
	fd = 0;
	count = 0;
	//t_point *map_coord;
	fd = open(path_file,O_RDONLY);
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break;
		split = ft_split(buffer, ' ');
		while (*split)
		{
			count++;
			split++;
		}
	}
	ft_printf("Count to malloc: %d\n", count);
	return (1);
}

int init_parser(char *path_file)
{
	save_values_to_struct(path_file);
	return (0);
}

