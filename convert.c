/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:52:39 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/21 15:52:43 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	takes a (valid) string and coverts to a bit array
*/

unsigned short	*convert(char *tetristr)
{
	unsigned short	*tetriarr;
	unsigned int	i;

	tetriarr = (unsigned short *)malloc(sizeof(unsigned short) * 27);
	i = 0;
	while (*tetristr)
	{
		if (*tetristr != '\n')
		{
			tetriarr[i] <<= 1;
			if (*tetristr == '#')
				tetriarr[i]++;
			tetristr++;
		}
		else if (*(++tetristr) == '\n')
		{
			i++;
			tetristr++;
		}
	}
	tetriarr[++i] = 0;
	return (tetriarr);
}
