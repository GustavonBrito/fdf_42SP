/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:59 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/10 01:19:51 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/headers/libft.h"
#include "libft/headers/ft_printf.h"
#include "includes/fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
	
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*destiny;

	destiny = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)destiny = color;
}

int	main(int argc, char **argv)
{
	if (init_validations(argc, argv) == 1)
		ft_printf("Validacoes realizadas com sucesso\n");
	if (init_parser(argv[1]))
		ft_printf("Parse realizado com sucesso");
}
// int		x;
// int		y;
// void	*mlx;
// void	*mlx_win;
// t_data	img;
// y = 0;
// mlx = mlx_init();
// mlx_win = mlx_new_window(mlx, 500, 500, "fdf");
// img.img = mlx_new_image(mlx, 500, 500);
// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 							&img.endian);
// while (y <= 50)
// {
// 	x = 0;
// 	while (x <= 50)
// 	{		
// 		my_mlx_pixel_put(&img, 225 + x, 225 + y, 0x0000ff);
// 		x++;
// 	}
// 	y++;
// }
// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// mlx_loop(mlx);
// mlx_destroy_display(mlx);
