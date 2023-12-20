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

int		check_vertical(t_boat boat, char* grid, int width, int length, char boat_cell)
{
	int		i;

	if (boat.y_axis + boat_size > length)
		return(1);
	return(0);
}

int		place_vertical(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	check_vertical(boat, grid, width, length, boat_cell);
	while (boat.size)
	{
		grid[boat.position] = boat_cell;
		boat.position += width + 1;
		boat.size--;
	}
	return(0);
}

int		check_around_h(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	int		i;
	int		position;

	if (boat.y_axis - 1 != -1)
	{
		i = 0;
		position = boat.position - width - 1;
		while (i <= size)
		{
			if (grid[position] == boat_cell)
				return(1);
			i++;
			position++;
		}
	}
	if (boat.y_axis + 2 < length)
	{
		i = 0;
		position = boat.position + width + 1;
		while (i <= size)
		{
			if (grid[position] == boat_cell)
				return(1);
			i++;
			position++;
		}
	}
	return(0);
}

int		check_horizontal(t_boat boat, char *grid, int width, int length, char boat_cell)
{
	int		i;

	if (boat.x_axis + boat.size > width)
		return(1);
	if (grid[boat.x_axis + boat.size] == boat_cell)
		return(1);
	if (boat.x_axis && grid[boat.x_axis - 1] == boat_cell)
		return(1);
	if (check_around_h(boat, grid, width, length, boat_cell))
		return(1);
	i = 0;
	while (i < boat.size)
	{
		if (grid[boat.position + i] == boat_cell)
			return(1);
		i++;
	}
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
		return(place_horizontal(boat, grid, width, boat_cell));
	else
		return(place_vertical(boat, grid, width, length, boat_cell));
}












