/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:06:39 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/17 20:26:27 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

int draw_line(t_mlx *mlx)
{
	int y;
	int x;
	
	y = -1;
	while(++y < mlx->map->max_y)
	{
		x = -1;
		while(++x < mlx->map->max_x)
		{
			if (x < mlx->map->max_x)
				draw_line();
			if (y < mlx->map->max_y)
				draw_line();
		}
	}
}

int init_render(t_mlx *mlx)
{
	
	return (0);
}

static void	draw_line(t_mlx *mlx, t_pts start, t_pts end)
{
	t_line	*line;

	line = init_line(mlx, start, end);
	isometric(line);
	bresenhams(mlx, line);
	free (line);
}