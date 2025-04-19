/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:03:10 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/18 21:18:03 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include "includes/fdf.h"

void	handle_error_code1(t_mlx *mlx)
{
	ft_printf("Erro na validacao da estrutura do mapa\n");
	if (mlx)
		free(mlx);
	exit(0);
}

void	handle_error_code2(t_mlx *mlx)
{
	ft_printf("Parser falhou!\n");
	if (mlx)
		free(mlx);
	exit(0);
}

void	handle_error_code3(t_mlx *mlx)
{
	ft_printf("Inicializacao da camera falhou\n");
	if (mlx)
		free(mlx);
	exit(0);
}

void	handle_error_code4(t_mlx *mlx)
{
	ft_printf("Erro na inicializacao mlx\n");
	if (mlx)
		free(mlx);
	exit(0);
}

void	handle_error_code5(t_mlx *mlx)
{
	ft_printf("Erro na validacao\n");
	if (mlx)
		free(mlx);
	exit(0);
}
