/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:31:49 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/13 22:51:52 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/libft.h"

void 		populate_pts(t_map *map);
void		parse_hex_to_map(char *buffer, t_map *map, int y, int x);
int			verify_hex(char *token);

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
	int		z_from_map;
	char	**split;

	split = ft_split(buffer, ',');
	z_from_map = ft_atoi(split[0]);
	map->coordinates[y][x].z = z_from_map;
	map->coordinates[y][x].rgb = ft_atoi_hexa(&split[1][2]);
	if (z_from_map > map->max_z)
		map->max_z = z_from_map;
	if (z_from_map < map->min_z)
		map->min_z = z_from_map;
	ft_free_split(split, NULL);
}

void populate_pts(t_map *map)
{
	int		x;
	int		i;
	
	x = -1;
	i = -1;
	// add (t_point **) to prevent undefined behavior
	map->coordinates = (t_point **)malloc(sizeof(t_point *) * map->max_y);
	if (!map->coordinates)
		return ;
	while (++x < map->max_y)
	{
		map->coordinates[x] = malloc(sizeof(t_point) * map->max_x);
		if (!map->coordinates[x])
		{
			while (++i <= x)
				free(map->coordinates[i]);
			return ;
		}
	}
}
