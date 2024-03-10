#include "so_long.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	t_game *so_long;
	so_long = malloc(sizeof(t_game));
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx,1080,1080,"SO_LONG");
	mlx_loop(so_long->mlx);
}