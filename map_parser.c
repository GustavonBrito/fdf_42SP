/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:31:29 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/13 14:51:41 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/messages.h"
#include "includes/fdf.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

///Objetivo: Abre o arquivo, aloca o mapa e preenche os dados usando parse_line_to_row.
// Depois tenho que fazer o free de map->coordinates, map->coordinates[j] e map;
t_map *read_and_alloc_map(int fd)
{
	char *buffer;
	char **split;
	int x;
	int y;
	int i;
	t_map *map = NULL;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	y = 0;
	i = 0;
	x = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		split = ft_split(buffer, ' ');
		while(split[x])
			x++;
		ft_free_split(split);
		free(buffer);
		y++;
	}
	map->max_x = x - 1;
	map->max_y = y;
	map->coordinates = malloc(sizeof(t_point *) * map->max_y);
	if (!map->coordinates)
		return (NULL);
	x = 0;
	while (x < map->max_y)
	{
		map->coordinates[x] = malloc(sizeof(t_point) * map->max_x);
		if (!map->coordinates[x])
		{
			while (i <= x)
			{
				free(map->coordinates[i]);
				i++;
			}
			return (NULL);
		}
		x++;
	}
	return (map);
}

// /Objetivo: Lê uma linha do mapa (ex: "1 0 0 -1 -1 0 ...") e armazena os valores em um array de t_point, setando também a coordenada y para cada ponto da linha.
//char *line,t_point *struct, int y
int parse_line_to_row(char *file_path, t_map *map)
{
	int		fd;
	char **split;
	char *buffer;
	int		x;
	int		y;

	y = 0;
	fd = open(file_path, O_RDONLY);
	while (y < map->max_y)
	{
		buffer = get_next_line(fd);
		split = ft_split(buffer, ' ');
		x = 0;
		while(x < map->max_x)
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
			x++;
		}
		y++;
	}
	close(fd);
	return (1);
}

//Objetivo: Ajusta todas as coordenadas x e y para que o centro do mapa fique na origem (0, 0). Isso melhora a projeção depois.
t_map *center_map(t_map *map, int width, int height)
{
	
	return (map);
}

//Objetivo: Converte os pontos do mapa para o sistema de projeção desejado (ex: isométrico), considerando os valores de z (profundidade).
//t_map apply_projection(t_map *map, int width, int height);

int init_parser(char *file_path)
{
	t_map *map;
	int fd;
	
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	map = read_and_alloc_map(fd);
	if (map == NULL)
		return (close_and_return_err(fd));
	if (parse_line_to_row(file_path, map) == -1)
		return (-1);
	map = center_map(map,map->max_x, map->max_y);
	if (map == NULL)
		return (-1);
	return (1);
}
