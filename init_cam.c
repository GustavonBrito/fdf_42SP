/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:02:50 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/14 21:34:46 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_cam *init_cam(t_map *map)
{
	t_cam *cam;
	
	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->offset_x = WIDTH / 2;
	cam->offset_y = HEIGHT / 2;
	cam->scale_z = 1;
	cam->scale_factor = get_scale(map);
	return (cam);
}
