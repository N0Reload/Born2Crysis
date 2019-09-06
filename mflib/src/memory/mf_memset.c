/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mf_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:17:10 by mfischer          #+#    #+#             */
/*   Updated: 2019/04/15 17:27:39 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfmemory.h"

void	*mf_memset(void *b, int c, size_t len)
{
	unsigned char *a;

	a = b;
	while (len--)
		*a++ = c;
	return (b);
}