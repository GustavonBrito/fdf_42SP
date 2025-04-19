/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:06:39 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 12:42:59 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_line(t_mlx *mlx, t_point start, t_point end);
static t_line	*init_line(t_mlx *mlx, t_point start, t_point end);
void			init_render(t_mlx *mlx);

void	init_render(t_mlx *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mlx->map->max_y)
	{
		x = -1;
		while (++x < mlx->map->max_x)
		{
			if (x < mlx->map->max_x - 1)
				draw_line(mlx, mlx->map->coordinates[y][x],
					mlx->map->coordinates[y][x + 1]);
			if (y < mlx->map->max_y - 1)
				draw_line(mlx, mlx->map->coordinates[y][x],
					mlx->map->coordinates[y + 1][x]);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

void	center(t_mlx *mlx, t_line *line)
{
	line->start.x += mlx->cam->offset_x;
	line->start.y += mlx->cam->offset_y;
	line->end.x += mlx->cam->offset_x;
	line->end.y += mlx->cam->offset_y;
}

void	scale(t_mlx *mlx, t_line *line)
{
	float	scale;

	scale = mlx->cam->scale_factor;
	line->start.x *= scale;
	line->start.y *= scale;
	line->end.x *= scale;
	line->end.y *= scale;
}

void	draw_line(t_mlx *mlx, t_point start, t_point end)
{
	t_line	*line;

	line = init_line(mlx, start, end);
	scale(mlx, line);
	apply_isometric(line);
	center(mlx, line);
	bresenham(mlx, line);
	free(line);
}

t_line	*init_line(t_mlx *mlx, t_point start, t_point end)
{
	t_line	*line;
	float	z_range;
	float	z_multiplier;

	z_range = mlx->map->max_z + abs(mlx->map->min_z);
	if (z_range > 50)
		z_multiplier = 1;
	else
		z_multiplier = 8;
	start.z *= z_multiplier;
	end.z *= z_multiplier;
	line = (t_line *)malloc(sizeof(t_line) * 1);
	if (!line)
		close_window(mlx);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.rgb = start.rgb;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.rgb = end.rgb;
	return (line);
}
