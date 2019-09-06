/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_switch_physics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:50:20 by mfischer          #+#    #+#             */
/*   Updated: 2019/09/05 18:00:09 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <doom_nukem.h>

int		bf_switch_physics(SDL_Event *event, t_libui_widget *widget, void *data)
{
	t_editor_interface	*ei;

	(void)event;
	ei = data;
	if (ei->is_physics == TRUE)
	{
		ei->is_physics = FALSE;
		libui_label_set_text(widget->shilds, "PHYSICS (OFF)");
		if (ei->is_modified && ei->item_placer)
			mesh_delete_physics(ei->item_placer);
	}
	else
	{
		ei->is_physics = TRUE;
		libui_label_set_text(widget->shilds, "PHYSICS (ON)");
		if (ei->is_modified && ei->item_placer)
		{
			mesh_delete_physics(ei->item_placer);
			mesh_add_physics(ei->item_placer,
				(ei->wall_friction_is_auto) ? -1 : ei->wall_friction);
		}
	}
	return (0);
}
