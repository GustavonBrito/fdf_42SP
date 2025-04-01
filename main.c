/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:59 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/01 00:51:17 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
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
	int i;
	int fd;
	
	i = 0;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd)
		{
			printf("File descriptor is not correct, check the archive");
			exit(1);
		}
		read_map();
	}
	close(fd);
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
