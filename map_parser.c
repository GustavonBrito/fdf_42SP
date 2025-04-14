/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:31:29 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/14 01:58:59 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

// Depois tenho que fazer o free de map->coordinates, map->coordinates[j] e map;

void	read_and_alloc_map(int fd, t_map *map);
int		parse_line_to_row(t_map *map, char *file_path);
t_map	*center_map(t_map *map);
t_map	*init_parser(char *file_path);

t_map	*init_parser(char *file_path)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read_and_alloc_map(fd, map);
	if (!map)
		return (close(fd), NULL);
	if (parse_line_to_row(map, file_path) == -1)
		return (NULL);
	map = center_map(map);
	if (!map)
		return (NULL);
	map = apply_projection(map);
	if (!map)
		return (NULL);
	return (map);
}

void	read_and_alloc_map(int fd, t_map *map)
{
	char	*buffer;
	char	**split;
	int		x;
	int		y;

	y = -1;
	x = 0;
	while (++y != -1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		split = ft_split(buffer, ' ');
		while (split[x] && split[x][0] != '\n')
			x++;
		ft_free_split(split, buffer);
	}
	map->max_x = x;
	map->max_y = y;
	populate_pts(map);
}

int	parse_line_to_row(t_map *map, char *file_path)
{
	char	**split;
	char	*buffer;
	int		fd;
	int		x;
	int		y;

	y = -1;
	fd = open(file_path, O_RDONLY);
	map->max_z = 0;
	map->min_z = 0;
	while (++y < map->max_y)
	{
		buffer = get_next_line(fd);
		split = ft_split(buffer, ' ');
		x = -1;
		while (++x < map->max_x)
		{
			if (verify_hex(split[x]) == IS_HEX)
				parse_hex_to_map(split[x], map, y, x);
			else
			{
				map->coordinates[y][x].z = ft_atoi(split[x]);
				map->coordinates[y][x].rgb = 0;
				if (ft_atoi(split[x]) > map->max_z)
					map->max_z = ft_atoi(split[x]);
				if (ft_atoi(split[x]) < map->min_z)
					map->min_z = ft_atoi(split[x]);
			}
			map->coordinates[y][x].x = x;
			map->coordinates[y][x].y = y;
		}
		ft_free_split(split, buffer);
	}
	close(fd);
	return (1);
}

t_map	*center_map(t_map *map)
{
	int	center_x;
	int	center_y;
	int	x;
	int	y;

	center_x = map->max_x / 2;
	center_y = map->max_y / 2;
	y = -1;
	while (++y < map->max_y)
	{
		x = -1;
		while (++x < map->max_x)
		{
			map->coordinates[y][x].x = x - center_x;
			map->coordinates[y][x].y = y - center_y;
		}
	}
	return (map);
}

// t_map	*apply_projection(t_map *map)
// {
// 	int		x;	
// 	int		y;
// 	int		original_x;
// 	int		original_y;
// 	float	z_multiplier;
// 	int 	z_range;

// 	z_range = map->max_z + abs(map->min_z);
// 	y = -1;
// 	if (z_range > 50)
// 		z_multiplier = 1;
// 	else
// 		z_multiplier = 8;
// 	while (++y < map->max_y)
// 	{
// 		x = -1;
// 		while (++x < map->max_x)
// 		{
// 			original_x = map->coordinates[y][x].x;
// 			original_y = map->coordinates[y][x].y;
// 			map->coordinates[y][x].x = (original_x - original_y) * cos(ISO_ANGLE);
// 			map->coordinates[y][x].y = ((original_x + original_y) * sin(ISO_ANGLE))
// 				- (map->coordinates[y][x].z * z_multiplier);
// 		}
// 	}
// 	return (map);
// }
