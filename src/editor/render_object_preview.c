/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_object_preview.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 00:25:41 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/12 13:35:55 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		render_object_preview(t_object *obj, SDL_Surface *surf, t_vec2i size)
{
	t_camera		camera;

	vec3_clear(&camera.pos);
	camera.view_dir = (t_vec3d){.a = {0, -1, 0}};
	generate_projection_matrix(&camera.projection_matrix, size);
	camera.view_matrix = look_at((t_vec3d){.a = {0, -50, 0}},
	(t_vec3d){.a = {0, 0, 0}}, (t_vec3d){.a = {0, -1, 0}});
	int i = -1;
	while (++i < 4)
	{
		int j = -1;
		while (++j < 4)
			camera.view_matrix[i][j];
	}
	render_object(obj, &camera, surf, NULL);
}