/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kf_fly_backwards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:19:43 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/18 11:58:56 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

void	kf_fly_backwards(void *param)
{
	t_e		*e;

	e = param;
	e->editor.editor_cam.pos = vec3vec3_add(e->editor.editor_cam.pos, vec3scalar_multiply(e->editor.editor_cam.view_dir, FLY_SPEED));
}