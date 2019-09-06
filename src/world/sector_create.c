/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 21:22:23 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/23 15:03:21 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void		sector_create(t_world *world)
{
	t_sector	*new;
	t_sector	tmp;

	if (!(new = (t_sector *)malloc(sizeof(t_sector) * (world->sectornum + 1))))
		return ;
	tmp.entites = NULL;
	tmp.id = world->sectornum;
	tmp.lights.light_count = 0;
	tmp.lights.lights = NULL;
	tmp.meshnum = 0;
	tmp.mesh = NULL;
	tmp.nb_entities = 0;
	tmp.src_portal = NULL;
	mf_memcpy(new, world->sectors, world->sectornum * sizeof(t_sector));
	new[world->sectornum] = tmp;
	world->sectornum++;
	if (world->sectors)
		free(world->sectors);
	world->sectors = new;
}
