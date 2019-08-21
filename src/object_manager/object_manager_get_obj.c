/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manager_get_obj.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 00:40:13 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/20 01:17:12 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_manager.h"

t_obj			*object_manager_get_obj(char *path)
{
	t_list2				*list;
	t_node				*head;

	if (!(list = get_object_list()))
		return (NULL);
	head = list->list;
	while (head)
	{
		if (strcmp(((t_object_resource *)head->data)->object_name, path) == 0)
			return (((t_object_resource *)head->data)->object);
		head = head->next;
	}
	if (object_manager_add(path) == 1)
		return (((t_object_resource *)list->list->data)->object);
	return (NULL);
}