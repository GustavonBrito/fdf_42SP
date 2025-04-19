/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:10 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/18 21:18:13 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include "includes/fdf.h"

void	handle_error_code1(t_mlx *mlx);
void	handle_error_code2(t_mlx *mlx);
void	handle_error_code3(t_mlx *mlx);
void	handle_error_code4(t_mlx *mlx);
void	handle_error_code5(t_mlx *mlx);

void	error_in_step(int error_code, t_mlx *mlx)
{
	if (error_code == 1)
		handle_error_code1(mlx);
	else if (error_code == 2)
		handle_error_code2(mlx);
	else if (error_code == 3)
		handle_error_code3(mlx);
	else if (error_code == 4)
		handle_error_code4(mlx);
	else if (error_code == 5)
		handle_error_code5(mlx);
}
