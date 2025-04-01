/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:14:02 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/01 01:02:01 by gustavo-lin      ###   ########.fr       */
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
	int		color;
}	t_point;

void    validate_map(char *filename);

int     parse_hex_value(char *str);

t_point *parse_line(char *line, int y, int cols);



#endif