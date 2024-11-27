#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(char *str)
{
	int		i;

	i = 0;
	ft_putstr("---------------------\n");
	while(str[i])
	{
		ft_putstr("|");
		ft_putchar(str[i]);
		if (str[i] == '\n')
			ft_putstr("---------------------\n");
		i++;
	}
}
