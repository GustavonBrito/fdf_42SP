/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:23:46 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 13:23:48 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;
	t_cam	*cam;

	if (argc != 2)
	{
		ft_printf(ERR_USAGE);
		return (1);
	}
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	if (init_validations(argc, argv) == -1)
		error_in_step(ERR_VALIDATION, mlx);
	map = init_parser(argv[1]);
	if (!map)
		error_in_step(ERR_PARSE, mlx);
	mlx->map = map;
	cam = init_cam(map);
	if (!cam)
		error_in_step(ERR_CAM, mlx);
	mlx->cam = cam;
	init_mlx(mlx);
	init_render(mlx);
	mlx_loop(mlx->mlx);
}
