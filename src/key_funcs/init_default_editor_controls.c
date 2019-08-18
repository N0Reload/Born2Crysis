/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default_editor_controls.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:41:38 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/18 13:35:25 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

void	init_default_editor_controls(t_input_map	*m, t_e *e)
{
	m->keys[SDL_SCANCODE_ESCAPE] = gen_key(&kf_quit_editor, e, FALSE);
    m->keys[SDL_SCANCODE_W] = gen_key(&kf_fly_forward, e, TRUE);
	m->keys[SDL_SCANCODE_A] = gen_key(&kf_fly_left, e, TRUE);
	m->keys[SDL_SCANCODE_D] = gen_key(&kf_fly_right, e, TRUE);
	m->keys[SDL_SCANCODE_S] = gen_key(&kf_fly_backwards, e, TRUE);
	m->keys[SDL_SCANCODE_SPACE] = gen_key(&kf_fly_up, e, TRUE);
	m->keys[SDL_SCANCODE_LCTRL] = gen_key(&kf_fly_down, e, TRUE);
}