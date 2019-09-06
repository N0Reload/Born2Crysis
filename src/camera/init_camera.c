/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:15:51 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/13 21:06:23 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void		init_camera(t_camera *cam, t_vec2i win_size)
{
	vec3_clear(&cam->pos);
	cam->pos.a[2] = -10;
	cam->pos.a[0] = 0;
	cam->pos.a[1] = 0;
	vec3_init(&cam->view_dir);
	generate_projection_matrix(&cam->projection_matrix, win_size);
}
