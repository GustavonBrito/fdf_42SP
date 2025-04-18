/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:29 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/18 12:39:37 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx/mlx.h"
#include "libft/headers/ft_printf.h"
#include <signal.h>
#include <X11/X.h>
#include <X11/Xlib.h>

void init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img = (t_data *)malloc(sizeof(t_data));
	if (!mlx->mlx)
		return ;
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf_42");
	mlx->img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel, &mlx->img->line_length, &mlx->img->endian);
	mlx_key_hook(mlx->win, close_by_esc, mlx);
	mlx_hook(mlx->win, 17, 0, close_by_x, mlx);
}
