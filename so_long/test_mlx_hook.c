#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int mlx_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		printf("you pressed ESC\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	printf("you didn't press ESC\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
	mlx_loop(vars.mlx);
}
