/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_function_to_library.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:39:28 by hmartzol          #+#    #+#             */
/*   Updated: 2019/09/03 17:39:30 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bmml_functions.h>
#include <mflib.h>

t_error_type	add_function_to_library_0(t_library *lib, const char *name)
{
	if ((lib->function_name = realloc_f(lib->function_name,
			sizeof(char*) * (1 + lib->nb_functions))) == NULL)
		return (ET_ALLOCATION_FAILED);
	if ((lib->function_name[lib->nb_functions] = strdup(name)) == NULL)
		return (ET_ALLOCATION_FAILED);
	if ((lib->function = realloc_f(lib->function,
		sizeof(t_function) * (1 + lib->nb_functions))) == NULL)
	{
		free(lib->function_name[lib->nb_functions]);
		return (ET_ALLOCATION_FAILED);
	}
	return (ET_OK);
}

t_error_type	add_function_to_library(t_library *lib, const char *name,
										t_function *func, int debug)
{
	uint64_t		it;
	t_error_type	t;

	it = 0;
	while (it < lib->nb_symbols && strcmp(lib->symbol[it].name, name))
		++it;
	if (it < lib->nb_symbols)
		return (ET_DUPLICATE_SYMBOL);
	it = 0;
	while (it < lib->nb_functions && strcmp(lib->function_name[it], name))
		++it;
	if (it < lib->nb_functions)
	{
		if (debug)
			mf_printf(
			"Library: Add function: Warning: redefined function'%s'\n", name);
		destroy_function(&lib->function[it]);
		lib->function[it] = *func;
		return (ET_OK);
	}
	if ((t = add_function_to_library_0(lib, name)) != ET_OK)
		return (t);
	lib->function[lib->nb_functions++] = *func;
	return (ET_OK);
}
