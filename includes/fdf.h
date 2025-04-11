/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:14:02 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/11 11:06:31 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
#define MINILIBX_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_point {
	
	int		x;
	int		y;
	int		z;
	int		rgb;
}	t_point;

int		init_validations(int argc, char **argv);
int		init_parser(char *file_path);
void	ft_free_split(char **array);
int		validate_element(const char *token);

#endif

// Parei na parte de validacao de hex, numeros positivos e negativos. depois eu preciso estudar sobre projecao isometrica