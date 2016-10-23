/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:32:31 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/22 17:31:17 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BLOCK_X pos.x + block % 4
#define BLOCK_Y pos.y + block / 4

static int	check_fit(unsigned short tetri, t_point pos, t_map *map)
{
	int block;

	block = 0;
	while (block < 16)
	{
		if ((32768 >> block) & tetri)
		{
			if (BLOCK_X >= 0 && BLOCK_X < map->size &&
				BLOCK_Y >= 0 && BLOCK_Y < map->size)
			{
				if (map->map[BLOCK_Y][BLOCK_X] != '.')
					return (0);
			}
			else
				return (0);
		}
		block++;
	}
	return (1);
}

static void	place_tet(t_map *map, unsigned short tetri, unsigned int tet_i,
	t_point pos)
{
	int		block;

	block = 0;
	while (block < 16)
	{
		if ((32768 >> block) & tetri)
			map->map[BLOCK_Y][BLOCK_X] = tet_i + 'A';
		block++;
	}
}

static void	remove_tet(t_map *map, unsigned short tetri, t_point pos)
{
	int	block;

	block = 0;
	while (block < 16)
	{
		if ((32768 >> block) & tetri)
			map->map[BLOCK_Y][BLOCK_X] = '.';
		block++;
	}
}

static int	solve(t_map *map, unsigned short *tetriarr, unsigned int tet_i)
{
	t_point pos;

	pos.y = -3;
	while (pos.y < map->size)
	{
		pos.x = -3;
		while (pos.x < map->size)
		{
			if (check_fit(tetriarr[tet_i], pos, map))
			{
				place_tet(map, tetriarr[tet_i], tet_i, pos);
				if (tetriarr[tet_i + 1])
				{
					if (solve(map, tetriarr, tet_i + 1))
						return (1);
					remove_tet(map, tetriarr[tet_i], pos);
				}
				else
					return (1);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void		solve_map(unsigned short *tetriarr)
{
	t_map			*map;
	unsigned int	tetri_ct;
	unsigned int	i;
	unsigned int	j;

	map = (t_map *)malloc(sizeof(t_map));
	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	tetri_ct = 0;
	while (tetriarr[tetri_ct])
		tetri_ct++;
	map->size = ft_sqrt_ceil(tetri_ct * 4);
	while (!solve(map, tetriarr, 0))
		(map->size)++;
	print_map(map);
}
