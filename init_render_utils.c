/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:30:47 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 11:56:45 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	new_end.y = (line->end.x + line->end.y) * sin(ISO_ANGLE) - line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	pixel;

	pixel = (y * data->line_length) + (x * 4);
	if (data->endian == 1)
	{
		data->addr[pixel + 1] = (color >> 16) & 0xFF;
		data->addr[pixel + 2] = (color >> 8) & 0xFF;
		data->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (data->endian == 0)
	{
		data->addr[pixel + 0] = (color) & 0xFF;
		data->addr[pixel + 1] = (color >> 8) & 0xFF;
		data->addr[pixel + 2] = (color >> 16) & 0xFF;
	}
}

static void	bresenham_init(t_bres *bresenham, t_line *line)
{
	bresenham->dx = abs(line->end.x - line->start.x);
	bresenham->dy = -abs(line->end.y - line->start.y);
	if (line->start.x < line->end.x)
		bresenham->step_x = 1;
	else
		bresenham->step_x = -1;
	if (line->start.y < line->end.y)
		bresenham->step_y = 1;
	else
		bresenham->step_y = -1;
	bresenham->decision_parameter = bresenham->dx + bresenham->dy;
	bresenham->x = line->start.x;
	bresenham->y = line->start.y;
}

static void	bresenham_draw(t_mlx *mlx, t_line *line, t_bres *bresenham)
{
	while (1)
	{
		if (bresenham->x >= 0 && bresenham->y >= 0 && bresenham->x < WIDTH
			&& bresenham->y < HEIGHT)
			my_mlx_pixel_put(mlx->img, bresenham->x, bresenham->y,
				line->start.rgb);
		if (bresenham->x == (int)line->end.x
			&& bresenham->y == (int)line->end.y)
			break ;
		bresenham->e2 = 2 * bresenham->decision_parameter;
		if (bresenham->e2 >= bresenham->dy)
		{
			bresenham->decision_parameter += bresenham->dy;
			bresenham->x += bresenham->step_x;
		}
		if (bresenham->e2 <= bresenham->dx)
		{
			bresenham->decision_parameter += bresenham->dx;
			bresenham->y += bresenham->step_y;
		}
	}
}

void	bresenham(t_mlx *mlx, t_line *line)
{
	t_bres	bresenham;

	bresenham_init(&bresenham, line);
	bresenham_draw(mlx, line, &bresenham);
}
