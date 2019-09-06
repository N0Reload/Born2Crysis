/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:43:13 by mfischer          #+#    #+#             */
/*   Updated: 2019/09/03 10:44:45 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void		render_mesh(t_mesh *mesh, t_camera *cam, SDL_Surface *surface,
	t_light_comp *lcomp)
{
	int32_t		count;
	t_sector	*tmp;
	t_polygon	*p;

	if (mesh->polygonnum * 2 > (int32_t)get_polygon_buffer_size())
		buffer_increase(mesh->polygonnum * 2);
	p = get_polygon_buffer();
	count = model_to_world(mesh, (t_vec4d){.c3 = {.vec3d = cam->pos}}, p);
	if (mesh->sector_id != -1 && count != 0)
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

void		render_invisible_mesh(t_mesh *mesh, t_camera *cam,
	SDL_Surface *surface, t_light_comp *lcomp)
{
	int			count;
	t_polygon	*p;

	if (mesh->polygonnum * 3 > (int32_t)get_polygon_buffer_size())
		buffer_increase(mesh->polygonnum * 3);
	p = get_polygon_buffer();
	count = model_to_world(mesh, (t_vec4d){.c3 = {.vec3d = cam->pos}}, p);
	polygons_set_trans(p, count, 100);
	light_to_world(lcomp);
	calculate_lighting(p, count, lcomp);
	world_to_view(p, count, cam->view_matrix);
	count = clip_znear(p, count);
	view_to_projection(p, count, cam->projection_matrix, surface);
	count = portal_clip(p, count, surface->w, surface->h);
	rasterize(p, count, surface, FALSE);
}

void		render_wireframe_mesh(t_mesh *mesh, t_camera *cam,
	SDL_Surface *surface, Uint32 color)
{
	int			count;
	t_polygon	*p;

	if (mesh->polygonnum * 3 > (int32_t)get_polygon_buffer_size())
		buffer_increase(mesh->polygonnum * 3);
	p = get_polygon_buffer();
	count = model_to_world(mesh, (t_vec4d){.c3 = {.vec3d = cam->pos}}, p);
	world_to_view(p, count, cam->view_matrix);
	count = clip_znear(p, count);
	view_to_projection(p, count, cam->projection_matrix, surface);
	count = portal_clip(p, count, surface->w, surface->h);
	rasterize_wireframe(p, count, surface, color);
}
