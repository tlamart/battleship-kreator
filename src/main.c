#include "battleshiplib.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

t_params	init_params(void)
{
	t_params	params = {LENGTH, WIDTH, EMPTY_CELL, BOAT_CELL};
	return(params);
}

int		get_grid_size(int length, int width)
{
	int		size;

	size = length * (width + 1);
	return(size);
}

char	*generate_grid(t_params params)
{
	char	*grid;
	int		i;
	int		grid_size;
	int		width;

	grid_size = get_grid_size(params.length, params.width);
	grid = malloc(sizeof(char) * (grid_size + 1));
	width = params.width;
	if (!grid)
		return(NULL);
	i = 0;
	while (i < grid_size)
	{
		grid[i] = params.empty_cell;
		if (width == 0)
		{
			grid[i] = '\n';
			width = params.width + 1;
		}
		i++;
		width--;
	}
	grid[i] = '\0';
	return(grid);
}

int		add_ships(char *grid, int width, int length)
{
	t_boat	*boats[5];
	int		boats_size[5] = {2, 3, 3, 4, 5};
	char	boat_cell;
	int		i;

	i = 0;
	boat_cell = 'A';
	while (i < 5)
	{
		boats[i] = gen_boat(width, length, boats_size[i]);
		//if (!boats[i]);
			//return(free_boats(boats, i));
		if (!place_boat(*boats[i], grid, width, length, boat_cell))
		{
			i++;
			boat_cell++;
		}

	}
	//free_boats(boats, 0);
	return(0);
}

//int		main(int ac, char **av)
int		main(void)
{
	t_params	params;
	char		*grid;

	//t_params = get_params(ac, av);
	srand(time(NULL)); // seed rand function;
	params = init_params();
	grid = generate_grid(params);
	add_ships(grid, params.width, params.length);
	ft_putstr("\n");
	ft_putstr(grid);
	ft_putstr("\n");
	free(grid);
	return(0);
}
