/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:14:03 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/22 23:04:36 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	a valid file with 26 tetri's is 545 bytes (sans nul terminator)
**	valid files are always (some multiple of 21) - 1
*/

static int	get_adjacent(char *tetri, unsigned int i)
{
	unsigned int	adjacent;

	adjacent = 0;
	if (i > 0 && tetri[i - 1] == '#')
		adjacent++;
	if (i < 19 && tetri[i + 1] == '#')
		adjacent++;
	if (i > 4 && tetri[i - 5] == '#')
		adjacent++;
	if (i < 14 && tetri[i + 5] == '#')
		adjacent++;
	return (adjacent);
}

static int	is_tetri(char *tetri)
{
	unsigned int	blocks;
	unsigned int	adjacent;
	unsigned int	i;

	blocks = 0;
	adjacent = 0;
	i = ~0;
	while (++i < 20)
	{
		if (i % 5 == 4)
		{
			if (tetri[i] != '\n')
				return (0);
		}
		else if (tetri[i] == '#')
		{
			blocks++;
			adjacent += get_adjacent(tetri, i);
		}
		else if (tetri[i] != '.')
			return (0);
	}
	if (blocks != 4 || adjacent < 6)
		return (0);
	return (1);
}

int			is_valid(char *tetristr)
{
	unsigned short	i;

	i = 0;
	while (tetristr[i])
	{
		if (!is_tetri(&tetristr[i]))
			return (0);
		i += 20;
		if (tetristr[i] == '\0')
			return (1);
		else if (tetristr[i] != '\n')
			return (0);
		i++;
	}
	return (0);
}
