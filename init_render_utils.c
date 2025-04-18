/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:30:47 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/18 12:40:12 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"
#include "minilibx/mlx.h"

void	apply_isometric(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ISO_ANGLE);
	new_start.y = (line->start.x + line->start.y) * sin(ISO_ANGLE)
		- line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ISO_ANGLE);
	new_end.y = (line->end.x + line->end.y) * sin(ISO_ANGLE)
		- line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int pixel = (y * data->line_length) + (x * 4);

	if (data->endian == 1)
	{
		data->addr[pixel + 1] = (color >> 16) & 0xFF;// Bit Red
		data->addr[pixel + 2] = (color >> 8) & 0xFF; // Bit Green
		data->addr[pixel + 3] = (color) & 0xFF; // Bit Blue
	}
	else if (data->endian == 0)
	{
		data->addr[pixel + 0] = (color) & 0xFF;
		data->addr[pixel + 1] = (color >> 8) & 0xFF;
		data->addr[pixel + 2] = (color >> 16) & 0xFF;
	}
}

void	bresenhams(t_mlx *mlx, t_line *line)
{
	int dx = abs(line->end.x - line->start.x);
	int dy = -abs(line->end.y - line->start.y);
	int sx = (line->start.x < line->end.x) ? 1 : -1;
	int sy = (line->start.y < line->end.y) ? 1 : -1;
	int err = dx + dy;

	int x = line->start.x;
	int y = line->start.y;

	while (1)
	{
		if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		{
			ft_printf("entrei\n");
			my_mlx_pixel_put(mlx->img, x, y, line->start.rgb);
		}
		if (x == (int)line->end.x && y == (int)line->end.y)
			break;
		int e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
	mlx_loop(mlx->mlx);
}
