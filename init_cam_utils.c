/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:23:10 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/19 13:27:33 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_scale(t_map *map)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	scale_x = WIDTH / (float)map->max_x;
	scale_y = HEIGHT / (float)map->max_y;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale / 1.75);
}
