#include "fillit.h"
#include <stdio.h>														//debug
#define BLOCK_X pos.x + block % 4
#define BLOCK_Y pos.y + block / 4

static int check_fit(unsigned short tetri, t_point pos, t_map *map)
{
	int block;
	
	block = 0;
	printf("chekcing fit %d\n", tetri);														//debug
	while (block < 16)
	{
		if ((32768 >> block) & tetri)
		{
			//printf("block at %d\n", block);										//debug
			if (BLOCK_X >= 0 && BLOCK_X < map->size && BLOCK_Y >= 0 && BLOCK_Y < map->size)
			{
				if (map->map[BLOCK_Y][BLOCK_X] != '.')
					return (0);
			}
			else
				return (0);
		}
	//	else
			//printf("no block at%d\n", block);											//debug
		block++;
	}
	printf("fits!\n");													//debug
	return (1);
}

static void 	print_map(t_map *map)
{
	int x;
	int y;

//	printf("printing!\n");									//debug
	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			write(1, &(map->map[y][x]), 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

static t_map	*place_tet(t_map *map, unsigned short tetri, unsigned int tet_i, t_point pos)
{
	t_map	*newmap;
	int		block;
	//int i;
	//int j;
	
	newmap = (t_map *)malloc(sizeof(t_map));
	/*
	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			newmap->map[i][j] = map->map[i][j];
			//printf("%c\n", newmap->map[i][j]);					//debug
			j++;
		}
		i++;
	}
	newmap->size = map->size;
	*/
	ft_memcpy(newmap, map, sizeof(t_map));
	block = 0;
	printf("placing tet\n");														//debug
	while (block < 16)
	{
		if ((32768 >> block) & tetri)
			newmap->map[BLOCK_Y][BLOCK_X] = tet_i + 'A';
		block++;
	}
	print_map(newmap);																	//debug
	return (newmap);
}


static t_map	*solve(t_map *map, unsigned short *tetriarr, unsigned int tet_i)
{
	//map->solved = 1;																	//debug
	//return (map);															//debug
	t_point pos;
	t_map	*newmap;
	
//	newmap = (t_map *)malloc(sizeof(t_map));
	pos.y = 0;
	while (pos.y < map->size)
	{
		pos.x = 0;
		while (pos.x < map->size)
		{
			if (check_fit(tetriarr[tet_i], pos, map))
			{
				newmap = place_tet(map, tetriarr[tet_i], tet_i, pos);
				if (tetriarr[tet_i + 1])										//check if next tet exists
				{
					if (solve(newmap, tetriarr, tet_i + 1)->solved)
						return (newmap);
				}
				else
				{
					map->solved = 1;
					map = place_tet(map, tetriarr[tet_i], tet_i, pos);
					return (map);
				}
				free(newmap);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (map);
}

void          solve_map(unsigned short *tetriarr)
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
	printf("map initialized\n");														//debug
	//*
	tetri_ct = 0;
	while (tetriarr[tetri_ct])
		tetri_ct++;
	map->size = ft_sqrt_ceil(tetri_ct * 4) - 1;
	map->solved = 0;
	while(!map->solved)
	{
		(map->size)++;
		map = solve(map, tetriarr, 0);
	}
	// */
 	print_map(map);
}

///////////////////////////////////////////////////////////////////////////////

/*
int check_fit(t_fillit map, t_tet tet, t_point point)
{
	int i;
	int xcheck;
	int ycheck;
	int MAX;
  
	//MAX = width and height of map
	MAX = map->current_size;
	i = 0;
	while (i < 4)
	{
		//tet->coords[i]->x = coord of sub block of tet relative to top left of piece
		//tet->coords[i]->y	= coord of sub block of tet relative to top left of piece
		//point->x 			= xcoord on map relative to top left of map
		//point->y 			= ycoord on map relative to top left of map
		//xcheck			= xcoord of sub block relative to top left of map
		//ycheck			= ycoord of sub block relative to top left of map
		
		xcheck = point->x + tet->coords[i]->x;
		ycheck = point->y + tet->coords[i]->y;
		if (xcheck <= MAX && 
			ycheck <= MAX && 
			map[xcheck][ycheck] != ' ')
		  return (0);
		i++;
	}
	return (1);
}
*/
///////////////////////////////////////////////////////////////////////////////                                                           
	/*
t_point pos_to_point(int pos, int width)
{
	t_point point;
  
	point->x = pos % width;
	point->y = pos / width;
	return (point);
}

int point_to_pos(t_point point, int width)
{
	int pos;
	
	pos = point->x + (width * point->y);
	return (pos);
}

*/
/*
void remove_tet()
{



}

int get_arr_pos(int x, int y)
{
  
  
  
}

short *load_tets(int filename)
{
  
  
}
*/
