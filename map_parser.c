/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:31:29 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/12 04:36:46 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/err_messages.h"
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
	int i;
	int y;
	int j;
	t_map *map = NULL;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	y = 0;
	j = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		split = ft_split(buffer, ' ');
		i = 0;
		while(split[i])
			i++;
		ft_free_split(split);
		free(buffer);
		y++;
	}
	map->max_x = i - 1;
	map->max_y = y;
	map->coordinates = malloc(sizeof(t_point *) * map->max_y);
	if (!map->coordinates)
		return (NULL);
	i = 0;
	while (i < map->max_y)
	{
		map->coordinates[i] = malloc(sizeof(t_point) * map->max_x);
		if (!map->coordinates[i])
		{
			while (j <= i)
			{
				free(map->coordinates[j]);
				j++;
			}
			return (NULL);
		}
		i++;
	}
	return (map);
}

// /Objetivo: Lê uma linha do mapa (ex: "1 0 0 -1 -1 0 ...") e armazena os valores em um array de t_point, setando também a coordenada y para cada ponto da linha.
//char *line,t_point *struct, int y
int parse_line_to_row(t_map *map, int fd)
{
	char *buffer;
	
	buffer = get_next_line(fd);
	
}

//Objetivo: Ajusta todas as coordenadas x e y para que o centro do mapa fique na origem (0, 0). Isso melhora a projeção depois.
//t_map center_map(t_map *map, int width, int height);


//Objetivo: Converte os pontos do mapa para o sistema de projeção desejado (ex: isométrico), considerando os valores de z (profundidade).
//t_map apply_projection(t_map *map, int width, int height);

int init_parser(char *file_path)
{
	t_map *map;
	int fd;
	
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = read_and_alloc_map(fd);
	if (map == NULL)
		return (close_and_return_err(fd));
	if (parse_line_to_row(map, fd) == -1)
		return (close_and_return_err(fd));
	return (1);
}
