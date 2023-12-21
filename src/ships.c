#include "battleshiplib.h"
#include <stdlib.h>
#include <stdio.h>

t_boat	*gen_boat(int width, int length, int size)
{
	t_boat	*boat;

	(void)length;
	boat = malloc(sizeof(t_boat));
	if (!boat)
		return(NULL);
	boat->x_axis = rand() % (width);
	boat->y_axis = rand() % (length);
	//boat->direction = rand() % 2;
	boat->direction = 0;
	boat->position = (boat->y_axis) * (width + 1) + boat-> x_axis;
	boat->size = size;
	printf("rand %d\n\n", rand());
	printf("boat:\n\tx = %d, y = %d, pos = %d, dir = %d, size = %d\n", boat->x_axis, boat->y_axis, boat->position, boat->direction, boat->size);
	return(boat);
}

int		check_vertical(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	(void)boat;
	(void)grid;
	(void)width;
	(void)length;
	(void)boat_cell;
	return(0);
}

int		place_vertical(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	if(check_vertical(boat, grid, width, length, boat_cell))
		return(1);
	while (boat.size)
	{
		grid[boat.position] = boat_cell;
		boat.position += width + 1;
		boat.size--;
	}
	return(0);
}

int		check_h(char *grid, int start, int size, char boat_cell)
{
	while (size)
	{
		if (grid[start] == boat_cell)
			return(1);
		start++;
		size--;
	}
	return(0);
}

int		check_horizontal(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	if (boat.x_axis + boat.size > width)
		return(1);
	if (boat.x_axis && grid[boat.x_axis - 1] == boat_cell)
		return(1);
	if (check_h(grid, boat.position, boat.size + 1, boat_cell))
		return(1);
	if (boat.y_axis && check_h(grid, boat.position - width - 2, boat.size + 2, boat_cell))
		return(1);
	if ((boat.y_axis + 1 < length) && check_h(grid, boat.position + width, boat.size + 2, boat_cell))
		return(1);
	return(0);
}

int		place_horizontal(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	if (check_horizontal(boat, grid, width,length, boat_cell))
		return(1);
	while(boat.size)
	{
		grid[boat.position] = boat_cell;
		boat.position++;
		boat.size--;
	}
	return(0);
}

int		place_boat(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	if (boat.direction == 0)
		return(place_horizontal(boat, grid, width, length, boat_cell));
	else
		return(place_vertical(boat, grid, width, length, boat_cell));
}
