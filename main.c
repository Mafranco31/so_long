#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	w1;

	if (initimg(&w1) == -1)
		return (0);	//	faire un msg d erreur
	if (argc != 2)
		return (0);	//	faire un msg d error
	w1.mlx = mlx_init();
	if (getlenxpm(argv[1], &w1) == -1)
		return (0);
	w1.win = mlx_new_window(w1.mlx, w1.width, w1.lenght, "./so_long");
	if (w1.win == NULL)
		return (0);	//	faire un msg d error
	w1.table = initmap(argv[1], &w1);
	if (!w1.table)
		return (0);
	mlx_key_hook(w1.win, pressech, &w1);
	mlx_loop(w1.mlx);
	return (0);
}
