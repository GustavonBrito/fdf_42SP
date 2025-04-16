/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:29 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/16 03:56:26 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx/mlx.h"
#include "libft/headers/ft_printf.h"
#include <signal.h>
#include <X11/X.h>
#include <X11/Xlib.h>

int close_window()
{
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	int y;
	
	if (keycode == 65307)
	{
		y = -1;
		while(++y < mlx->map->max_y)
			free(mlx->map->coordinates[y]);
		free(mlx->map->coordinates);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->cam);
		free(mlx->map);
		free(mlx);
		exit(0);
	}
	return (0);
}

int init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf_42");
	//mlx->img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx);
	mlx_destroy_display(mlx);
	return (1);
}