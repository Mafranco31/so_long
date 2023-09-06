#include "../so_long.h"

static void	putimg(t_data *w1, char c, int x, int y)
{
	void	*ptr;

	if (c == '0')
		ptr = w1->img.grass; 
	if (c == '1')
		ptr = w1->img.fence; 
	if (c == 'C')
		ptr = w1->img.hotdog; 
	if (c == 'E')
		ptr = w1->img.kennel; 
	if (c == 'P')
	{
		ptr = w1->img.dog; 
		w1->img.dogx = x;
		w1->img.dogy = y;
	}
	mlx_put_image_to_window(w1->mlx, w1->win, ptr, x * 45, y * 45);
}

void	initmap(t_data *w1)
{
	int	i;
	int	j;

	i = 0;
	printf("width = %d, lenght = %d\n", w1->width, w1->lenght);
	while (i < w1->width)
	{
		j = 0;
		while (j < w1->lenght)
		{
			printf("x = %d, y = %d, c = %c\n", i, j, w1->table[i][j]);
			putimg(w1, w1->table[i][j], j, i);
			j++;
		}
		i++;
	}
}
