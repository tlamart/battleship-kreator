#ifndef BATTLESHIPLIB
# define BATTLESHIPLIB
# define LENGTH 10
# define WIDTH 10
# define EMPTY_CELL '-'
# define BOAT_CELL 'X'

struct	s_params {
	int		length;
	int		width;
	char	empty_cell;
	char	boat_cell;
};

struct	s_boat {
	int		x_axis;
	int		y_axis;
	int		position;
	int		direction;
	int		size;
};

typedef struct s_params t_params;
typedef struct s_boat t_boat;

void	ft_putstr(char *str);
void	ft_print_grid(char *str);

t_boat	*gen_boat(int width, int length, int size);
int		place_boat(t_boat boat, char *grid, int width, int length, char boat_cell);

#endif
