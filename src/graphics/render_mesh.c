/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:43:13 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/20 17:10:17 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void		render_mesh(t_mesh *mesh, t_camera *cam, SDL_Surface *surface,
	t_light_comp *lcomp)
{
	Uint32		count;
	t_sector	*tmp;
	t_polygon	*p;

	if (mesh->polygonnum * 2 > get_polygon_buffer_size())
		buffer_increase(mesh->polygonnum * 2);
	p = get_polygon_buffer();
	count = model_to_world(mesh, (t_vec4d){.c3 = {.vec3d = cam->pos}}, p);
	if (mesh->sector_id != (Uint32)-1 && count != 0)
	{
		tmp = get_sector(mesh->sector_id, get_world());
		tmp->src_portal = mesh;
		sector_queue_push(tmp);
		return ;
	}
	light_to_world(lcomp);
	calculate_lighting(p, count, lcomp);
	world_to_view(p, count, cam->view_matrix);
	count = clip_znear(p, count);
	view_to_projection(p, count, cam->projection_matrix, surface);
	count = portal_clip(p, count, surface->w, surface->h);
	rasterize(p, count, surface, FALSE);
}
