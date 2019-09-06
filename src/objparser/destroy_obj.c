/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:16:29 by mfischer          #+#    #+#             */
/*   Updated: 2019/09/01 18:42:42 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objparser.h"

void		destroy_obj(t_obj **obj)
{
	while ((*obj)->vertices->size)
		free(list2_pop((*obj)->vertices));
	while ((*obj)->vertices_uv->size)
		free(list2_pop((*obj)->vertices_uv));
	while ((*obj)->normals->size)
		free(list2_pop((*obj)->normals));
	while ((*obj)->indices->size)
		free(list2_pop((*obj)->indices));
	if ((*obj)->normals_s)
		free((*obj)->normals_s);
	if ((*obj)->vertices_s)
		free((*obj)->vertices_s);
	if ((*obj)->vertices_uv_s)
		free((*obj)->vertices_uv_s);
	free(*obj);
	*obj = NULL;
}
