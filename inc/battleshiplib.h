#ifndef BATTLESHIPLIB
# define BATTLESHIPLIB
# define LENGTH 10
# define WIDTH 10

struct	s_params {
	int		length;
	int		width;
	char	empty_cell;
	char	boat_cell;
};

typedef struct s_params t_params;

#endif
