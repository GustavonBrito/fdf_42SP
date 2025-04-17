/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:06 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/17 12:30:14 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include "includes/fdf.h"

// int main(void)
// {
// 	int		x;
// 	int		y;
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	y = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "fdf");
// 	img.img = mlx_new_image(mlx, 500, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	while (y <= 50)
// 	{
// 		x = 0;
// 		while (x <= 50)
// 		{		
// 			my_mlx_pixel_put(&img, 225 + x, 225 + y, 0x0000ff);
// 			x++;
// 		}
// 		y++;
// 	}
// 	lx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	mlx_destroy_display(mlx);
// 	return(0);
// }

// void debug_print_pts(t_map *map)
// {
// 	int row = -1, col;
// 	while (++row < map->max_y)
// 	{
// 		col = -1;
// 		while (++col < map->max_x)
// 		ft_printf("Point: z = %d, x = %d, y = %d\n", map->coordinates[row][col].z, col, row);
// 		ft_printf("\n");
// 	}
// }


int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;
	t_cam	*cam;

	if (init_validations(argc, argv) == 1)
		ft_printf("Validacoes realizadas com sucesso\n");
	else
	{
		ft_printf("Validacao fahou!");
		exit(0);
	}
	map = init_parser(argv[1]);
	if (!map)
	{
		ft_printf("Parser falhou!\n");
		exit(0);
	}
	ft_printf("Parse realizado com sucesso\n");
	cam = init_cam(map);
	if (!cam)
	{
		ft_printf("Inicializacao da camera falhou\n");
		exit(0);
	}
	ft_printf("Inicialização da camera feita\n");
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->cam = cam;
	mlx->map = map;
	if (init_mlx(mlx) == 1)
		ft_printf("Inicializacao do MLX feita com sucesso");
	else
		ft_printf("Error na inicializacao do MLX");
}
