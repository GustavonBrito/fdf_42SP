/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:23:21 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 13:23:22 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img = (t_data *)malloc(sizeof(t_data));
	if (!mlx->img)
		return ;
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF_42");
	mlx->img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel,
			&mlx->img->line_length, &mlx->img->endian);
	mlx_key_hook(mlx->win, close_by_esc, mlx);
	mlx_hook(mlx->win, 17, 0, close_by_x, mlx);
}
