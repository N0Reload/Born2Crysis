/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:10:27 by lmunoz-q          #+#    #+#             */
/*   Updated: 2019/09/02 19:14:43 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objparser.h"

static int	get_type_s(char *line)
{
	int i;

	i = 0;
	while (*line && !mf_isdigit(*line))
		line++;
	while (*line && *line != ' ')
		if (*line++ == '/')
			i++;
	return (i);
}

t_bool		get_indices(t_list2 *l, char *line, int *tex)
{
	int format;

	format = get_type_s(line);
	if (format == 0)
		get_ints_format_one(l, line, tex);
	if (format == 1)
		get_ints_format_two(l, line, tex);
	if (format == 2)
		get_ints_format_three(l, line, tex);
	if (format > 2)
		return (FALSE);
	return (TRUE);
}

t_bool		iread_line(t_obj *obj, char *line, int *tex, char **mtl)
{
	if (*line == 'v' && *(line + 1) == 'n')
	{
		get_vertices(obj->normals, line + (sizeof(char) * 2), 3);
		obj->has_normals = TRUE;
	}
	if (*line == 'f' && *(line + 1) == ' ')
		if (!(get_indices(obj->indices, line + 1, tex)))
			return (FALSE);
	if (mf_strstr(line, "mtllib"))
	{
		if (*mtl)
		{
			free(*mtl);
			*mtl = NULL;
		}
		if (!(*mtl = mf_strjoin("assets/mtls/", get_mtl_name(line))))
			return (FALSE);
	}
	if (mf_strstr(line, "usemtl"))
		*tex = get_mtl_tex(line, *mtl);
	return (TRUE);
}

t_bool		read_line(t_obj *obj, char *line, int *tex)
{
	static char	*mtl = NULL;

	if (tex == NULL)
	{
		if (mtl)
			free(mtl);
		mtl = NULL;
		return (FALSE);
	}
	while (mf_isspace(*line))
		line++;
	if (*line == '#')
		return (TRUE);
	if (*line == 'v' && *(line + 1) == ' ')
		get_vertices(obj->vertices, line + sizeof(char), 3);
	if (*line == 'v' && *(line + 1) == 't')
	{
		get_vertices(obj->vertices_uv, line + (sizeof(char) * 2), 2);
		obj->has_texture = TRUE;
	}
	if (!(iread_line(obj, line, tex, &mtl)))
		return (FALSE);
	return (TRUE);
}
