/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:30:47 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/17 19:18:18 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

t_map	*apply_projection(t_map *map)
{
	int		x;
	int		y;
	int		original_x;
	int		original_y;
	float	z_multiplier;
	int 	z_range;

	z_range = map->max_z + abs(map->min_z);
	y = -1;
	if (z_range > 50)
		z_multiplier = 1;
	else
		z_multiplier = 8;
	while (++y < map->max_y)
	{
		x = -1;
		while (++x < map->max_x)
		{
			original_x = map->coordinates[y][x].x;
			original_y = map->coordinates[y][x].y;
			map->coordinates[y][x].x = (original_x - original_y) * cos(ISO_ANGLE);
			map->coordinates[y][x].y = ((original_x + original_y) * sin(ISO_ANGLE))
				- (map->coordinates[y][x].z * z_multiplier);
		}
	}
	return (map);
}

void	my_mlx_pixel_put(t_data *data, t_mlx *mlx, int x, int y, int color)
{
	int color = 0xABCDEF;

	if (data->bits_per_pixel != 32)
		color = mlx_get_color_value(mlx, color);
	
	int pixel = (y * data->line_length) + (x * 4);

	if (data->endian == 1)
	{
		data->addr[pixel + 0] = (color >> 24);
		data->addr[pixel + 1] = (color >> 16) & 0xFF;
		data->addr[pixel + 2] = (color >> 8) & 0xFF;
		data->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (data->endian == 0)
	{
		data->addr[pixel + 0] = (color) & 0xFF;
		data->addr[pixel + 1] = (color >> 8) & 0xFF;
		data->addr[pixel + 2] = (color >> 16) & 0xFF;
		data->addr[pixel + 3] = (color >> 24);
	}
}


