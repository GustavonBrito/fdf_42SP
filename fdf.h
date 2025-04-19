/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:23:03 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 13:23:04 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/headers/libft.h"
# include "libft/headers/ft_printf.h"
# include "libft/headers/get_next_line.h"
# include "messages.h"

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# include <X11/X.h>
# include <X11/Xlib.h>

# define ISO_ANGLE 0.523599
# define WIDTH 1400
# define HEIGHT 900
# define RED 16711680
# define IS_HEX 16

typedef struct s_bres
{
	int		dx;
	int		dy;
	int		step_x;
	int		step_y;
	int		decision_parameter;
	int		e2;
	int		x;
	int		y;
}			t_bres;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_cam
{
	float	scale_factor;
	float	scale_z;
	int		offset_x;
	int		offset_y;
}			t_cam;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		rgb;
}			t_point;

typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}			t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_cam	*cam;
	t_data	*img;
}			t_mlx;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}			t_line;

int			init_validations(int argc, char **argv);
t_map		*init_parser(char *file_path);
t_cam		*init_cam(t_map *map);
void		init_mlx(t_mlx *mlx);
void		init_render(t_mlx *mlx);
void		ft_free_split(char **array, char *buffer);
int			validate_element(const char *token);
void		free_buffer_gnl(char *buffer, int fd);
int			verify_hex(char *token);
void		parse_hex_to_map(char *split, t_map *map, int y, int x);
void		populate_pts(t_map *map);
float		get_scale(t_map *map);
void		apply_isometric(t_line *line);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			close_by_x(t_mlx *mlx);
int			close_by_esc(int keycode, t_mlx *mlx);
void		close_window(t_mlx *mlx);
void		bresenham(t_mlx *mlx, t_line *line);
void		error_in_step(int error_code, t_mlx *mlx);
int			count_words_spaces(char *line);

#endif