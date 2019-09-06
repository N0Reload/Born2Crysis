/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:44:18 by mfischer          #+#    #+#             */
/*   Updated: 2019/04/13 14:52:07 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfmath.h"

t_vec4d	vec3vec4_convert(t_vec3d vec)
{
	return ((t_vec4d){.a = {vec.n.x, vec.n.y, vec.n.z, 0.0}});
}