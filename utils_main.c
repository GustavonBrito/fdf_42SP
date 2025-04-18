/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:10 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/18 20:02:10 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include "includes/fdf.h"

void	error_in_step(int error_code)
{
	if (error_code == 1)
	{
		ft_printf("Erro na validacao da estrutura do mapa\n");
		exit(0);
	}
	if (error_code == 2)
	{
		ft_printf("Parser falhou!\n");
		exit(0);
	}
	if (error_code == 3)
	{
		ft_printf("Inicializacao da camera falhou\n");
		exit(0);
	}
	if (error_code == 4)
	{
		ft_printf("Erro na inicializacao mlx\n");
		exit(0);
	}
	if (error_code == 5)
	{
		ft_printf("Erro na validacao\n");
		exit(0);
	}
}
