/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:31:29 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/13 16:51:36 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/messages.h"
#include "includes/fdf.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

///Objetivo: Abre o arquivo, aloca o mapa e preenche os dados usando parse_line_to_row.
// Depois tenho que fazer o free de map->coordinates, map->coordinates[j] e map;

static void	populate_pts(t_map *map);
void		read_and_alloc_map(int fd, t_map *map);
int			parse_line_to_row(t_map *map, char *file_path);
t_map		*init_parser(char *file_path);

t_map	*init_parser(char *file_path)
{
	t_map *map;
	int fd;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read_and_alloc_map(fd, map);
	if (map == NULL)
		return (close_and_return_err(fd), NULL);
	if (parse_line_to_row(map, file_path) == -1)
		return (NULL);
	// map = center_map(map,map->max_x, map->max_y);
	if (map == NULL)
		return (NULL);
	return (map);
}

static void populate_pts(t_map *map)
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

void	read_and_alloc_map(int fd, t_map *map)
{
	char *buffer;
	char **split;
	int x;
	int y;
	
	y = -1;
	while (++y != -1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		x = 0;
		split = ft_split(buffer, ' ');
		while(split[x])
			x++;
		ft_free_split(split, buffer);
	}
	map->max_x = x;
	map->max_y = y;
	ft_printf("X: %d\n", map->max_x);
	ft_printf("Y: %d\n", map->max_y);
	populate_pts(map);
}

// /Objetivo: Lê uma linha do mapa (ex: "1 0 0 -1 -1 0 ...") e armazena os valores em um array de t_point, setando também a coordenada y para cada ponto da linha.
//char *line,t_point *struct, int y
int parse_line_to_row(t_map *map, char *file_path)
{
	char	**split;
	char	*buffer;
	int		fd;
	int		x;
	int		y;

	y = -1;
	fd = open(file_path, O_RDONLY);
	while (++y < map->max_y)
	{
		buffer = get_next_line(fd);
		split = ft_split(buffer, ' ');
		x = -1;
		while(++x < map->max_x)
		{
			if (verify_hex(split[x]) == IS_HEX)
				parse_hex_to_map(split[x], map, y, x);
			else
			{
				map->coordinates[y][x].z = ft_atoi(split[x]);
				map->coordinates[y][x].rgb = 0;
			}
			map->coordinates[y][x].x = x;
			map->coordinates[y][x].y = y;
		}
	}
	close(fd);
	return (1);
}

//Objetivo: Ajusta todas as coordenadas x e y para que o centro do mapa fique na origem (0, 0). Isso melhora a projeção depois.
// t_map *center_map(t_map *map, int width, int height)
// {
	
// 	return (map);
// }

//Objetivo: Converte os pontos do mapa para o sistema de projeção desejado (ex: isométrico), considerando os valores de z (profundidade).
//t_map apply_projection(t_map *map, int width, int height);

