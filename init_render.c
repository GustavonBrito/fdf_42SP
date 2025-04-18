/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:06:39 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/18 12:22:23 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "minilibx/mlx.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

static void		draw_line(t_mlx *mlx, t_point start, t_point end);
static void		send_coordenates_to_render(t_mlx *mlx);
static t_line	*init_line(t_mlx *mlx, t_point start, t_point end);
int				init_render(t_mlx *mlx);

int init_render(t_mlx *mlx)
{
	send_coordenates_to_render(mlx);
	return (1);
}
static void send_coordenates_to_render(t_mlx *mlx)
{
	int y;
	int x;
	
	y = -1;
	while(++y < mlx->map->max_y)
	{
		x = -1;
		while(++x < mlx->map->max_x)
		{
			if (x < mlx->map->max_x - 1)
				draw_line(mlx, mlx->map->coordinates[y][x], mlx->map->coordinates[y][x + 1]);
			if (y < mlx->map->max_y - 1)
				draw_line(mlx, mlx->map->coordinates[y][x], mlx->map->coordinates[y + 1][x]);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

static void	draw_line(t_mlx *mlx, t_point start, t_point end)
{
	t_line	*line;

	line = init_line(mlx, start, end);
	apply_isometric(line);
	bresenhams(mlx, line);
	free (line);
}

static t_line	*init_line(t_mlx *mlx, t_point start, t_point end)
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
