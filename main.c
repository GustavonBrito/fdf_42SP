/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:59 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/14 02:22:23 by gustavo-lin      ###   ########.fr       */
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
	t_map	*map;
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
}