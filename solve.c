#include "fillit.h"

static int check_fit(short tetri, t_point pos, t_map *map)
{
	int tetripos;
	
  	tetripos = 0;
  	while (tetripos < 16)
    {
    	/*
     	if (tetri[tetripos]) 
          	if (pos + tetripos != INSIDE_MAP || map[pos + tetripos] != FITS)
          		return (0);
          		*/
        tetripos++;
    }
  	return (1);
  	tetri = 0;																//debug
  	pos.x = 0;																//debug
  	map = NULL;																//debug

}

static t_map	*place_tet(t_map *map, unsigned short *tetriarr, unsigned int tet_i, t_point pos)
{
	map->solved = 1;												//debug
	tetriarr = NULL;												//debug
	tet_i = 0;												//debug
	pos.x = 0;												//debug


	return (map);
}

static void	print_map(t_map *map)
{
	map = NULL;																								//debug
}

static t_map *solve(t_map *map, unsigned short *tetriarr, unsigned int tet_i)
{
  	t_point pos;
  	t_map	*newmap;
  	
  	newmap = (t_map *)malloc(sizeof(t_map));
  	pos.y = 0;
	while (pos.y < map->size)
	{
	  	pos.x = 0;
      	while (pos.x < map->size)
        {
            if (check_fit(tetriarr[tet_i], pos, map))
            {
                if (tetriarr[tet_i + 1])										//check if next tet exists
                {
                  newmap = place_tet(map, tetriarr, tet_i, pos);
                  if ((newmap = solve(newmap, tetriarr, tet_i + 1))->solved)
                		return (newmap);
                }
                else
                {
                	map->solved = 1;
                	return (map);
                }
            }
            pos.x++;
        }
      	pos.y++;
	}
  	return (map);
}

void          solve_map(unsigned short *tetriarr)
{
    t_map *map;
    
    map = (t_map *)malloc(sizeof(t_map));
  map->size = 2;
    while(!map->solved)
    {
        solve(map, tetriarr, 0);
        map->size++;
    }
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
