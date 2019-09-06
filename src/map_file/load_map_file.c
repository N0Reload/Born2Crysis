/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:43:15 by lmunoz-q          #+#    #+#             */
/*   Updated: 2019/09/06 11:48:24 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_file.h>

Uint8	*load_meshes(Uint8 *p, t_mesh *buf, Uint32 c)
{
	t_map_file_mesh	*fm;
	int32_t			it;

	buf = &buf[-1];
	while (c-- && (buf = &buf[1]))
	{
		fm = (t_map_file_mesh*)p;
		*buf = (t_mesh){.polygonnum = fm->nb_polygons,
		.polygons = SDL_malloc(sizeof(t_polygon) * fm->nb_polygons),
		.matrix = fm->matrix, .sector_id = fm->sector_id,
		.portal_normal = fm->portal_normal, .radius = fm->radius,
		.nb_walls = fm->nb_walls, .on_contact = (t_effet){fm->on_contact, {0}},
		.walls = SDL_malloc(sizeof(t_wall) * fm->nb_walls)};
		if ((it = -1) && ((buf->polygonnum && buf->polygons == NULL)
				|| (buf->nb_walls && buf->walls == NULL)))
			return (NULL);
		p = (Uint8*)&fm[1];
		SDL_memcpy(buf->polygons, p, sizeof(t_polygon) * buf->polygonnum);
		p += sizeof(t_polygon) * buf->polygonnum;
		SDL_memcpy(buf->walls, p, sizeof(t_wall) * buf->nb_walls);
		while (++it < buf->nb_walls)
			buf->walls[it].parent_mesh = buf;
		p += sizeof(t_wall) * buf->nb_walls;
	}
	return (p);
}

Uint8	*load_sectors(Uint8 *p, t_sector *buf, Uint32 c)
{
	t_map_file_sector	*sp;

	buf = &buf[-1];
	while (c-- && (buf = &buf[1]))
	{
		sp = (t_map_file_sector*)p;
		p = (Uint8*)&sp[1];
		*buf = (t_sector){.lights = {.light_count = sp->nb_lights,
				.lights = SDL_malloc(sizeof(t_light) * sp->nb_lights)},
			.nb_entities = sp->nb_entities, .entites = SDL_malloc(
				sizeof(t_eidos_frame) * sp->nb_entities),
			.meshnum = sp->nb_mesh, .mesh = SDL_malloc(
				sizeof(t_mesh) * sp->nb_mesh),
			.physics = sp->physics, .id = sp->id};
		if ((buf->lights.light_count && buf->lights.lights == NULL)
				|| (buf->nb_entities && buf->entites == NULL)
				|| (buf->meshnum && buf->mesh == NULL)
				|| (p = load_meshes(p, buf->mesh, sp->nb_mesh)) == NULL)
			return (NULL);
		SDL_memcpy(buf->lights.lights, p, sp->nb_lights * sizeof(t_light));
		p += sp->nb_lights * sizeof(t_light);
	}
	return (p);
}

Uint8	*load_textures(Uint8 *p, t_texture *buf, Uint32 c)
{
	t_map_file_texture	*ft;

	buf = &buf[-1];
	while (c-- && (buf = &buf[1]))
	{
		ft = (t_map_file_texture*)p;
		p = (Uint8*)&ft[1];
		*buf = (t_texture){.size = ft->size, .id = ft->id, .mode = ft->mode,
			.texture = SDL_CreateRGBSurface(SDL_SWSURFACE, ft->size.n.x,
				ft->size.n.y, 32, 0xFF0000, 0xFF00, 0xFF, 0xFF000000)};
		if (buf->texture == NULL)
			return (NULL);
		SDL_memcpy(buf->path, ((t_map_file_texture*)p)->path,
			sizeof(buf->path));
		p = (Uint8*)&ft[1];
		SDL_memcpy(buf->texture->pixels, p,
			buf->size.n.x * buf->size.n.y * sizeof(Uint32));
		p += buf->size.n.x * buf->size.n.y * sizeof(Uint32);
	}
	return (p);
}

t_world	map_file_to_world(t_map_file *stream)
{
	Uint8		*p;
	t_world		out;
	uint64_t	nb_func;

	out = (t_world){.sectornum = stream->nb_sectors,
		.goal_point = stream->spawn_point, .nb_textures = stream->nb_textures,
		.lib = get_world()->lib};
	nb_func = stream->nb_functions;
	p = (Uint8*)&stream[1];
	if ((out.skybox = SDL_malloc(sizeof(t_mesh))) == NULL
		|| (out.textures = SDL_malloc(
			sizeof(t_texture) * out.nb_textures)) == NULL
		|| (out.sectors = SDL_malloc(sizeof(t_sector) * out.sectornum))
		== NULL
		|| ((p = load_meshes(p, out.skybox, 1)) == NULL)
		|| ((p = load_textures(p, out.textures, stream->nb_textures)) == NULL)
		|| (p = load_sectors(p, out.sectors, out.sectornum)) == NULL
		|| load_lib(p, &out.lib, nb_func) == NULL)
		return ((t_world){.sectornum = 0});
	link_library(&out.lib, 1);
	out.effect_statics = mf_memalloc(sizeof(void*) * out.lib.nb_functions);
	return (out);
}
