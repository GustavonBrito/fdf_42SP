/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:14:02 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/13 17:13:34 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
#define MINILIBX_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_point {
	
	int		x;
	int		y;
	int		z;
	int		rgb;
}	t_point;

typedef struct s_map {
	t_point		**coordinates;
	int			max_x;
	int			max_y;
	int			max_z;
	int			min_z;
}	t_map;

int		init_validations(int argc, char **argv);
// int		init_parser(char *path_file);
t_map	*init_parser(char *file_path);
void	ft_free_split(char **array, char *buffer);
int		validate_element(const char *token);
void	free_buffer_gnl(char *buffer, int fd);
void	close_and_return_err(int fd); //? REFACT THIS IN FUTURE
int		verify_hex(char *token);
void	parse_hex_to_map(char *split,t_map *map, int y, int x);


#endif

// Parei na parte de validacao de hex, numeros positivos e negativos. depois eu preciso estudar sobre projecao isometrica