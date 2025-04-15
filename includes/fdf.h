/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:14:02 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/15 01:29:55 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
#define MINILIBX_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#define ISO_ANGLE	0.523599
#define WIDTH		1400
#define HEIGHT		900


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_cam
{
	float		scale_factor;
	float		scale_z;
	float		offset_x;
	float		offset_y;
}		t_cam;

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

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_cam	*cam;
	t_data	*img;
}	t_mlx;

int			init_validations(int argc, char **argv);
t_map		*init_parser(char *file_path);
t_cam		*init_cam(t_map *map);
int			init_mlx(t_mlx *mlx);
void		ft_free_split(char **array, char *buffer);
int			validate_element(const char *token);
void		free_buffer_gnl(char *buffer, int fd);
int			verify_hex(char *token);
void		parse_hex_to_map(char *split,t_map *map, int y, int x);
void		populate_pts(t_map *map);
float		get_scale(t_map *map);

#endif
// Parei na parte de validacao de hex, numeros positivos e negativos. depois eu preciso estudar sobre projecao isometrica