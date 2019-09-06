/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_lux_fallof_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:24:24 by tfernand          #+#    #+#             */
/*   Updated: 2019/08/22 13:32:38 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <doom_nukem.h>

int	decrease_lux_fallof_number(SDL_Event *event, t_libui_widget *widget,
	void *data)
{
	t_editor_interface	*editor_interface;

	(void)event;
	(void)widget;
	editor_interface = (t_editor_interface *)data;
	if (editor_interface->lux_fallof > 0)
		editor_interface->lux_fallof -= 1;
	if (editor_interface->lux_fallof < 0)
		editor_interface->lux_fallof = 0;
	update_lux_fallof_text(&(editor_interface->lux_fallof_selec_label),
		editor_interface->lux_fallof);
	return (0);
}

int	decreasedot1_lux_fallof_number(SDL_Event *event, t_libui_widget *widget,
	void *data)
{
	t_editor_interface *editor_interface;

	(void)event;
	(void)widget;
	editor_interface = (t_editor_interface *)data;
	if (editor_interface->lux_fallof > 0)
		editor_interface->lux_fallof -= 0.1;
	if (editor_interface->lux_fallof < 0)
		editor_interface->lux_fallof = 0;
	update_lux_fallof_text(&(editor_interface->lux_fallof_selec_label),
		editor_interface->lux_fallof);
	return (0);
}

int	increase_lux_fallof_number(SDL_Event *event, t_libui_widget *widget,
	void *data)
{
	t_editor_interface *editor_interface;

	(void)event;
	(void)widget;
	editor_interface = (t_editor_interface *)data;
	if (editor_interface->lux_fallof < MAX_FALLOF_INTENSITY)
		editor_interface->lux_fallof += 1;
	if (editor_interface->lux_fallof > MAX_FALLOF_INTENSITY)
		editor_interface->lux_fallof = MAX_FALLOF_INTENSITY;
	update_lux_fallof_text(&(editor_interface->lux_fallof_selec_label),
		editor_interface->lux_fallof);
	return (0);
}

int	increasedot1_lux_fallof_number(SDL_Event *event, t_libui_widget *widget,
	void *data)
{
	t_editor_interface *editor_interface;

	(void)event;
	(void)widget;
	editor_interface = (t_editor_interface *)data;
	if (editor_interface->lux_fallof < MAX_FALLOF_INTENSITY)
		editor_interface->lux_fallof += 0.1;
	if (editor_interface->lux_fallof > MAX_FALLOF_INTENSITY)
		editor_interface->lux_fallof = MAX_FALLOF_INTENSITY;
	update_lux_fallof_text(&(editor_interface->lux_fallof_selec_label),
		editor_interface->lux_fallof);
	return (0);
}
