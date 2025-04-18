/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:06 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/18 20:02:52 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "minilibx/mlx.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;
	t_cam	*cam;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	if (init_validations(argc, argv) == -1)
		error_in_step(ERR_VALIDATION);
	map = init_parser(argv[1]);
	if (!map)
		error_in_step(ERR_PARSE);
	mlx->map = map;
	cam = init_cam(map);
	if (!cam)
		error_in_step(ERR_CAM);
	mlx->cam = cam;
	init_mlx(mlx);
	if (mlx->mlx == NULL)
		error_in_step(ERR_MLX);
	init_render(mlx);
	mlx_loop(mlx->mlx);
}
