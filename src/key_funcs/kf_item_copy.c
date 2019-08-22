/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kf_item_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:41:58 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/21 18:27:48 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

static void     get_target_mesh(t_e *e)
{
	t_vec4d		pos;
	double		dot;
	Uint32		i;
	Uint32		j;

	dot = 0;
	i = (Uint32)-1;
	while (++i < e->world.sectornum)
	{
		j = (Uint32)-1;
		while (++j < e->world.sectors[i].meshnum)
		{
			vec4_init(&pos);
			pos = mat4vec4_multiply(e->world.sectors[i].mesh[j].matrix, pos);
			if (vec3vec3_dist(pos.c3.vec3d, e->editor.editor_cam.pos) > ZFAR)
				return ;
			if (vec3_dot(e->editor.editor_cam.view_dir, vec3_normalize(vec3vec3_substract(pos.c3.vec3d, e->editor.editor_cam.pos))) < dot)
			{
				dot = vec3_dot(e->editor.editor_cam.view_dir, vec3_normalize(vec3vec3_substract(pos.c3.vec3d, e->editor.editor_cam.pos)));
				e->editor.selected_mesh = &e->world.sectors[i].mesh[j];
				printf("%p ", e->editor.selected_mesh);
			}
		}
	}
	printf("\n");
}

void		kf_item_copy(void *param)
{
	t_e	 *e;

	e = param;
	if (!e->editor.is_in_view)
	{
		return ;
	}
	e->editor.dist = ZFAR;
	e->editor.selected_mesh = NULL;
	get_target_mesh(e);
	if (e->editor.selected_mesh)
	{
		//free mesh
		e->editor.item_placer = mesh_copy(e->editor.selected_mesh);
	}
}
