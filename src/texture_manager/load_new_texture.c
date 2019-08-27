/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_new_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:46:30 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/27 19:04:44 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_manager.h"

int					is_texture_already_created(char *path)
{
	int			i;
	t_texture	*list;
	int			size;

	i = -1;
	list = get_texture_list();
	size = get_texture_list_size();
	while (++i < size)
		if (!strcmp(path, list[i].path))
			return (i);
	return (-1);
}

int					load_texture_from_x(char *path, t_texture_mode mode)
{
	t_texture	*new;
	t_texture	*list;
	t_texture	tex;
	int			tmp;

	tex.texture = NULL;
	printf("%s\n", path);
	tmp = is_texture_already_created(path);
	if (tmp != -1)
		return (tmp);
	list = get_texture_list();
	if (mf_strlen(path) > 511 ||
		!(tex.texture = IMG_Load(path)) ||
		!(new = (t_texture *)malloc(sizeof(t_texture) * (get_texture_list_size() + 1))))
	{
		puts("Failed to load ");
		puts(path);
		puts(" into the texture manager!");
		return (-1);
	}
	tex.texture = SDL_ConvertSurfaceFormat(tex.texture, SDL_PIXELFORMAT_ARGB8888, 0);
	if (list)
		mf_memcpy(new, list, get_texture_list_size() * sizeof(t_texture));
	if (list)
		free(list);
	tex.id = get_texture_list_size();
	tex.mode = mode;
	tex.size = (t_vec2i){.a = {tex.texture->w, tex.texture->h}};
	mf_strcpy(tex.path, path);
	new[get_texture_list_size()] = tex;
	mf_strcpy(new[get_texture_list_size()].path, path);
	set_texture_list(new, get_texture_list_size() + 1);
	return (tex.id);
}

int					load_texture_from_bmp(char *path, t_texture_mode mode)
{
	t_texture	*new;
	t_texture	*list;
	t_texture	tex;
	int			tmp;

	tex.texture = NULL;
	printf("%s\n", path);
	tmp = is_texture_already_created(path);
	if (tmp != -1)
		return (tmp);
	list = get_texture_list();
	if (mf_strlen(path) > 511 ||
		!(tex.texture = libui_surface_image_load_32argb_scale(path, 1, 1)) ||
		!(new = (t_texture *)malloc(sizeof(t_texture) * (get_texture_list_size() + 1))))
	{
		puts("Failed to load ");
		puts(path);
		puts(" into the texture manager!");
		return (-1);
	}
	if (list)
		mf_memcpy(new, list, get_texture_list_size() * sizeof(t_texture));
	if (list)
		free(list);
	tex.id = get_texture_list_size();
	tex.mode = mode;
	tex.size = (t_vec2i){.a = {tex.texture->w, tex.texture->h}};
	mf_strcpy(tex.path, path);
	new[get_texture_list_size()] = tex;
	mf_strcpy(new[get_texture_list_size()].path, path);
	set_texture_list(new, get_texture_list_size() + 1);
	return (tex.id);
}
