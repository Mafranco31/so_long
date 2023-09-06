#include "../include/so_long.h"

static int	checkgetE(char **table, int y, int x, int dx, int dy)
{
	table[y][x] = '1';
	if (x == dx && y == dy)
		return (0);
	if (table[y + 1][x] != '1')
		if (checkgetE(table, y + 1, x, dx, dy) == 0)
			return (0);
	if (table[y - 1][x] != '1')
		if (checkgetE(table, y - 1, x, dx, dy) == 0)
			return (0);
	if (table[y][x + 1] != '1')
		if (checkgetE(table, y, x + 1, dx, dy) == 0)
			return (0);
	if (table[y][x - 1] != '1')
		if (checkgetE(table, y, x - 1, dx, dy) == 0)
			return (0);
	return (1);
}
static int	checkgetC(char **table, int y, int x, int dx, int dy)
{
	table[y][x] = '1';
	if (x == dx && y == dy)
		return (0);
	if (table[y + 1][x] != '1' && table[y + 1][x] != 'E')
		if (checkgetC(table, y + 1, x, dx, dy) == 0)
			return (0);	
	if (table[y - 1][x] != '1' && table[y + 1][x] != 'E')
		if (checkgetC(table, y - 1, x, dx, dy) == 0)
			return (0);
	if (table[y][x + 1] != '1' && table[y][x + 1] != 'E')
		if (checkgetC(table, y, x + 1, dx, dy) == 0)
			return (0);
	if (table[y][x - 1] != '1' && table[y][x - 1] != 'E')
		if (checkgetC(table, y, x - 1, dx, dy) == 0)
			return (0);
	return (1);
}

static void	searchdog(t_data *w1)
{
	int	x;
	int	y;

	y = 1;
	while (w1->table[y])
	{
		x = 1;
		while (w1->table[y][x])
		{
			if (w1->table[y][x] == 'P')
			{
				w1->img.dogx = x;
				w1->img.dogy = y;
				return ;
			}
		x++;
		}
	y++;
	}
}

int	checkpath(t_data *w1, int y, int x, int i)
{
	char	**copy;

	searchdog(w1);
	while (w1->table[y])
	{
		x = 1;
		while (w1->table[y][x])
		{
			if (w1->table[y][x] == 'C' || w1->table[y][x] == 'E')
			{
				copy = create1tab(w1);
				if (w1->table[y][x] == 'C')
					i = checkgetC(copy, y, x, w1->img.dogx, w1->img.dogy);
				else if (w1->table[y][x] == 'E')
					i = checkgetE(copy, y, x, w1->img.dogx, w1->img.dogy);
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
