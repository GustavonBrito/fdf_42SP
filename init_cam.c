/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gserafio <gserafio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:31:21 by gserafio          #+#    #+#             */
/*   Updated: 2025/04/17 12:31:24 by gserafio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/headers/ft_printf.h"

t_cam *init_cam(t_map *map)
{
	t_cam *cam;
	
	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->offset_x = WIDTH / 2.0;
	cam->offset_y = HEIGHT / 2.0;
	cam->scale_z = 1;
	cam->scale_factor = get_scale(map);
	return (cam);
}
