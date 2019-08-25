/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kf_preview_rotate_pitch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:03:01 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/18 16:04:17 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

void		kf_preview_rotate_pitch_r(void *param)
{
	t_e		*e;
	t_vec4d	rot;

	e = param;
	rot = quat_rotator((t_vec3d){{1, 0, 0}}, ROTATE_SPEED);
	e->editor.item_rotation = quat_multiply(rot, e->editor.item_rotation);
}

void		kf_preview_rotate_pitch_l(void *param)
{
	t_e		*e;
	t_vec4d	rot;

	e = param;
	rot = quat_rotator((t_vec3d){{1, 0, 0}}, -ROTATE_SPEED);
	e->editor.item_rotation = quat_multiply(rot, e->editor.item_rotation);
}
