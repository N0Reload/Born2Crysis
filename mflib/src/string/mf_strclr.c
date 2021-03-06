/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mf_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:18:49 by mfischer          #+#    #+#             */
/*   Updated: 2019/04/15 17:37:42 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfstring.h"

void	mf_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
