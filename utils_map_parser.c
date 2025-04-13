/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:31:49 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/13 16:32:38 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/libft.h"

void	close_and_return_err(int fd)
{
	close(fd);
}

int	verify_hex(char *token)
{
	int	i;

	i = 0;
	while (ft_isdigit(token[i]) == 1 || token[i] == '-')
		i++;
	if (token[i] != ',' && token[i] != '\0' && token[i] != '\n')
		return (-1);
	if (token[i] == ',')
	{
		if (token[i + 1] == '0' && token[i + 2] == 'x')
			return (IS_HEX);
	}
	else if (token[i] == '\n')
		return (1);
	return (1);
}

// Ficar de olho aonde eu vou liberar essa memoria depois de utilizar
void	parse_hex_to_map(char *buffer, t_map *map, int y, int x)
{
	char	**split;

	split = ft_split(buffer, ',');
	map->coordinates[y][x].z = ft_atoi(split[0]);
	map->coordinates[y][x].rgb = ft_atoi_hexa(&split[1][2]);
	ft_free_split(split, NULL);
}
