/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:14:03 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/21 19:25:58 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	a valid file with 26 tetri's is 545 bytes (sans nul terminator)
**	valid files are always (some multiple of 21) - 1
*/

static int	has_adjacent(char *tetri, unsigned int i)
{
	return ((i > 0 && tetri[i - 1] == '#') || (i < 19 && tetri[i + 1] == '#')
		|| (i > 4 && tetri[i - 5] == '#') || (i < 14 && tetri[i + 5] == '#'));
}

static int	is_tetri(char *tetri)
{
	unsigned int	blocks;
	unsigned int	i;

	blocks = 0;
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
			if (!has_adjacent(tetri, i))
				return (0);
		}
		else if (tetri[i] != '.')
			return (0);
	}
	if (blocks != 4)
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
