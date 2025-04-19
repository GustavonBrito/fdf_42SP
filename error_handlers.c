/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:22:55 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 13:22:58 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
