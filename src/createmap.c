#include "../include/so_long.h"

static	int	checkconst(t_data *w1, int nbE, int nbP)
{
	if (w1->count <= 0)
		return (endbefore(w1, "MAP NEED AT LEAST 1 C (hotdog)"));
	if (nbE != 1)
		return (endbefore(w1, "MAP NEED ONLY 1 E (kennel)"));
	if (nbP != 1)
		return (endbefore(w1, "MAP NEED ONLY 1 P (dog)"));
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
			if (w1->table[i][j] == 'C')
				w1->count++;
			else if (w1->table[i][j] == 'E')
				k++;
			else if (w1->table[i][j] == 'P')
				l++;
			else if (w1->table[i][j] != '0' && w1->table[i][j] != '1')
				return (endbefore(w1, "YOU ONLY CAN PUT 0 / 1 / C / E / P IN YOUR MAP"));
			j++;
		}
		i++;
	}
	return (checkconst(w1, k, l));
}
