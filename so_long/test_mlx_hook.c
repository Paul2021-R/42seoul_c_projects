#include "so_long.h"

int	main(void)
{
	t_mlx	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1024, 768, "Hello world!");
	//Press ESC, Press other key
	mlx_hook(vars.mlx_win, 2, 1L<<0, key_hook_switch, &vars);
	//resizsing of window
	mlx_hook(vars.mlx_win, 25, 1L<<18, window_resizing, &vars);
	//event of buttons
	mlx_hook(vars.mlx_win, 5, 1L<<3, buttons_press, &vars);	
	//event of long
	
	//event of mouse in & out
	mlx_hook(vars.mlx_win, 6, 1L<<4, mouse_inout, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
