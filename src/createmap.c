#include "../include/so_long.h"

static int	checkgetC(char **table, int y, int x, int dx, int dy)
{
	table[y][x] = '1';
	if (x == dx && y == dy)
		return (0);
	if (table[y + 1][x] != '1' && table[y + 1][x] != 'E')
		if (checkgetC(table, y + 1, x, dx ,dy) == 0)
			return (0);	
	if (table[y - 1][x] != '1' && table[y + 1][x] != 'E')
		if (checkgetC(table, y - 1, x, dx ,dy) == 0)
			return (0);
	if (table[y][x + 1] != '1' && table[y][x + 1] != 'E')
		if (checkgetC(table, y, x + 1, dx ,dy) == 0)
			return (0);
	if (table[y][x - 1] != '1' && table[y][x - 1] != 'E')
		if (checkgetC(table, y, x - 1, dx ,dy) == 0)
			return (0);
	return (1);
}

static int	checkpath(t_data *w1, int y, int i)
{
	char	**copy;
	int	x;
	
	while (w1->table[y])
	{
		x = 0;
		while (w1->table[y][x])
		{
			if (w1->table[y][x] == 'C')
			{
				copy = create1tab(w1);
				i = checkgetC(copy, y, x, w1->img.dogx, w1->img.dogy);
				freeall(copy, w1->width);
				if (i == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	putimg(t_data *w1, char c, int x, int y)
{
	void	*ptr;

	ptr = NULL;
	if (c == '0')
		ptr = w1->img.grass; 
	else if (c == '1')
		ptr = w1->img.fence; 
	else if (c == 'C')
		ptr = w1->img.hotdog; 
	else if (c == 'E')
		ptr = w1->img.kennel; 
	else if (c == 'P')
	{
		ptr = w1->img.dog; 
		w1->img.dogx = x;
		w1->img.dogy = y;
	}
	else
		return (end(w1, "MAP ONLY NEED TO HAVE 0 / 1 / C / E / P AND NO CHAR MISSED", 1));
	mlx_put_image_to_window(w1->mlx, w1->win, ptr, x * 45, y * 45);
	return (0);
}

static	int	checkconst(t_data *w1, int nbE, int nbP)
{
	if (w1->count <= 0)
		return (end(w1, "MAP NEED AT LEAST 1 C (hotdog)", 1));
	if (nbE != 1)
		return (end(w1, "MAP NEED ONLY 1 E (kennel)", 1));
	if (nbP != 1)
		return (end(w1, "MAP NEED ONLY 1 P (dog)", 1));
	if (checkpath(w1, 0, 0) == 1)
		return (end(w1, "MAP NEED A VALID WAY TO WIN", 1));
	return (0);
}

int	initmap(t_data *w1, int k, int l)
{
	int	i;
	int	j;

	i = 0;
	while (i < w1->width)
	{
		j = 0;
		while (j < w1->lenght)
		{
			if (putimg(w1, w1->table[i][j], j, i) == 1)
				return (1);
			if (w1->table[i][j] == 'C')
				w1->count++;
			if (w1->table[i][j] == 'E')
				k++;
			if (w1->table[i][j] == 'P')
				l++;
			j++;
		}
		i++;
	}
	return (checkconst(w1, k, l));
}
