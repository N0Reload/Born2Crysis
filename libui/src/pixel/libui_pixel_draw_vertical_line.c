/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_pixel_draw_vertical_line.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:26:55 by hmartzol          #+#    #+#             */
/*   Updated: 2019/03/05 20:26:57 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libui_pixel.h>

int	libui_pixel_draw_vertical_line(SDL_Surface *surface,
	t_libui_pixel_coord point, int length, Uint32 color)
{
	int	i;

	if (length > 0)
	{
		i = -1;
		while (++i < length)
			libui_pixel_set(surface, point.x, point.y + i, color);
	}
	else
	{
		i = 1;
		while (--i > length)
			libui_pixel_set(surface, point.x, point.y + i, color);
	}
	return (0);
}

int	libui_pixel_draw_vertical_line_atomic(SDL_Surface *surface,
	t_libui_pixel_coord point, int length, Uint32 color)
{
	int	i;

	SDL_LockSurface(surface);
	if (length > 0)
	{
		i = -1;
		while (++i < length)
			libui_pixel_set(surface, point.x, point.y + i, color);
	}
	else
	{
		i = 1;
		while (--i > length)
			libui_pixel_set(surface, point.x, point.y + i, color);
	}
	SDL_UnlockSurface(surface);
	return (0);
}
