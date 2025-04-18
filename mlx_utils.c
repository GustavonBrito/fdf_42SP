/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:23:57 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 13:23:59 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_mlx *mlx)
{
	int	y;

	y = -1;
	if (mlx->img->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->map->coordinates)
	{
		while (++y < mlx->map->max_y)
			free(mlx->map->coordinates[y]);
		free(mlx->map->coordinates);
		free(mlx->cam);
		free(mlx->map);
	}
	if (mlx->img)
		free(mlx->img);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	if (mlx)
		free(mlx);
	exit(0);
}

int	close_by_x(t_mlx *mlx)
{
	close_window(mlx);
	return (0);
}

int	close_by_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		close_window(mlx);
	return (0);
}
