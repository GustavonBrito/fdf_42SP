/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:03:38 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/18 10:35:13 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx/mlx.h"
#include "libft/headers/ft_printf.h"
#include <signal.h>
#include <X11/X.h>
#include <X11/Xlib.h>

void close_window(t_mlx *mlx)
{
	int y;
	y = -1;
	if (mlx->img->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->map->coordinates)
	{
		while(++y < mlx->map->max_y)
			free(mlx->map->coordinates[y]);
		free(mlx->map->coordinates);
		free(mlx->cam);
		free(mlx->map);
	}
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free(mlx);
	exit(0);
}

int close_by_x(t_mlx *mlx)
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