/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:17:35 by tfernand          #+#    #+#             */
/*   Updated: 2019/08/31 19:12:22 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	editor_render(t_e *e, t_libui_widgets_surface *ws,
	t_editor_interface *editor_interface)
{
	mf_memset(ws->surface->pixels, 0,
		ws->surface->pitch * ws->surface->h);
	mf_memset(editor_interface->view_container.texture->pixels, 0,
		editor_interface->view_container.texture->pitch
		* editor_interface->view_container.texture->h);
	mf_memset(editor_interface->preview_container.texture->pixels, 0,
		editor_interface->preview_container.texture->pitch
		* editor_interface->preview_container.texture->h);
	editor_interface->editor_cam.view_dir = e->input_map.mouse.front;
	remplir_preview(editor_interface);
	remplir_3dview(editor_interface, e);
	mf_memset(get_zbuff(), 0,
		e->win->surface->w * e->win->surface->h * sizeof(double));
	libui_window_update(e->win);
}
