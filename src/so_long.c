#include "../include/so_long.h"

static void	putimg2(t_data *w1, char c, int y, int x)
{
	if (c == '0')
		mlx_put_image_to_window(w1->mlx, w1->win, w1->img.grass, x * 45, y * 45);
	if (c == '1')
		mlx_put_image_to_window(w1->mlx, w1->win, w1->img.fence, x * 45, y * 45);
	if (c == 'C')
		mlx_put_image_to_window(w1->mlx, w1->win, w1->img.hotdog, x * 45, y * 45);
	if (c == 'E')
		mlx_put_image_to_window(w1->mlx, w1->win, w1->img.kennel, x * 45, y * 45);
	if (c == 'P')
		mlx_put_image_to_window(w1->mlx, w1->win, w1->img.dog, x * 45, y * 45);
}

int	expose(t_data *w1)
{
	int	i;
	int	j;

	i = 0;
	while (w1->table[i])
	{
		j = 0;
		while (w1->table[i][j])
		{
			putimg2(w1, w1->table[i][j], i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	mouseget(t_data *w1)
{
	end(w1, "WINDOW EXIT", 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	w1;

	if (argc != 2)
	{
		printf("Error\nTHIS PROGRAM NEEDS 1 PATH FOR MAP, AND NO MORE THAN 1 ARGUMENT");
		return (0);
	}
	w1.path = ft_strdup(argv[1]);
	if (initdata(&w1) == 1)
		return (0);
	//if (checkmap(&w1) == 1)
	//	return (0);
	if (initmap(&w1, 0, 0) == 1)
		return (0);
	w1.win = mlx_new_window(w1.mlx, w1.lenght * 45, w1.width * 45, "./so_long");
	if (w1.win == NULL)
		return (endbefore(&w1, "CREATING WINDOW FAILED"));
	if (makeimg(&w1) == 1)
		return (end(&w1, "CREATING IMAGES FAILED", 1));
	mlx_key_hook(w1.win, presskey, &w1);
	mlx_expose_hook(w1.win, expose, &w1);
	mlx_hook(w1.win, 17, 1L<<17, mouseget, &w1);
	mlx_loop(w1.mlx);
}
