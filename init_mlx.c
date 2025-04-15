/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:29 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/15 02:44:45 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx/mlx.h"
#include "libft/headers/ft_printf.h"
#include <signal.h>

// int	mouse_hook(int keycode, t_mlx *mlx)
// {
// 	(void) mlx;
	
// 	ft_printf("%d", keycode);
// 	ft_printf("Hello from key_hook!\n");
// 	return (0);
// }

int	key_hook(int keycode, t_mlx *mlx)
{
	(void) mlx;
	if (keycode == 65307)
	{
		kill(getpid(), SIGTERM);
	}
	return (0);
}

int init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf_42");
	mlx->img = mlx_new_image(mlx, mlx->cam->offset_x, mlx->cam->offset_y);
	mlx_key_hook(mlx->win, key_hook, mlx);
	//mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
	return (1);
}