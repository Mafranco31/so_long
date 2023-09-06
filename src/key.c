#include "../so_long.h"

static void	moovedog(t_data *w1, int dx, int dy)
{
	int	x;
	int	y;

	x = w1->img.dogx + dx;
	y = w1->img.dogy + dy;
	printf("%d, %d\n", x, y);
	if (w1->table[x][y] == 48)
		write(1, "yea", 4);
	mlx_put_image_to_window(w1->mlx, w1->win, w1->img.grass, w1->img.dogx, w1->img.dogy);
	mlx_put_image_to_window(w1->mlx, w1->win, w1->img.dog, x, y);
	w1->img.dogx = x;
	w1->img.dogy = y;
}

int	presskey(int kcode, t_data *w1)
{
	if (kcode == 65307)
		mlx_destroy_window(w1->mlx, w1->win);	//	gerer destruction
	if (kcode == 119)
		moovedog(w1, 0, -1);
	if (kcode == 97)
		moovedog(w1, -1, 0);
	if (kcode == 115)
		moovedog(w1, 0, 1);
	if (kcode == 100)
		moovedog(w1, 1, 0);
	return (0);
}
