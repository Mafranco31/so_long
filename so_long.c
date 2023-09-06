#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	w1;

	(void)argc;
	initdata(&w1, argv[1]);
	initmap(&w1);
	printf("%d, %d\n", w1.img.dogx, w1.img.dogy);
	mlx_key_hook(w1.win, presskey, &w1);
	mlx_loop(w1.mlx);
}
