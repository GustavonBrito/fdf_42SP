/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:59 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/13 16:57:07 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/headers/libft.h"
#include "libft/headers/ft_printf.h"
#include "includes/fdf.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;
	
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*destiny;

// 	destiny = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)destiny = color;
// }

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
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	mlx_destroy_display(mlx);
// 	return(0);
// }

void debug_print_pts(t_map *map)
{
	int x, y;

	x = -1;
	while (++x < map->max_y)
	{
		y = -1;
		while (++y < map->max_x)
			ft_printf("Point: z = %d, x = %d, y = %d\n", map->coordinates[x][y].z, y, x);
	}
}
int	main(int argc, char **argv)
{
	t_map	*map;
	if (init_validations(argc, argv) == 1)
		ft_printf("Validacoes realizadas com sucesso\n");
	map = init_parser(argv[1]);
	if (!map)
		ft_printf("PARSER FAILED\n");
	ft_printf("Parse realizado com sucesso\n");
	ft_printf("max X: %d | max Y: %d\n", map->max_x, map->max_y);
	debug_print_pts(map);
}