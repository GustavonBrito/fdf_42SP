/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:31:10 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/17 12:31:11 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "includes/messages.h"
#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

//mlx->img = mlx_new_image(mlx, mlx->cam->offset_x, mlx->cam->offset_y);
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*destiny;

// 	destiny = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)destiny = color;
// }