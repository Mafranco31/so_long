#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include "include/libft.h"
# include <fcntl.h>

typedef struct	s_img
{
	void	*dog;
	void	*fence;
	void	*grass;
	void	*hotdog;
	void	*kennel;
	int	h;
	int	w;
	int	dogx;
	int	dogy;
}		t_img;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	int	lenght;
	int	width;
	t_img	img;
	char	**table;
}		t_window;

typedef struct	s_coordonnees
{
	int	x;
	int	y;
}		t_coordonnees;


typedef struct	s_cadrillage
{
	int	xstart;
	int	ystart;
	int	xlign;
	int	ylign;
}		t_cadrillage;

int	create_trgb(int t, int r, int g, int b);

int	pressech(int kcode, t_window *w1);

int	getlenxpm(char *path, t_window *w1);

int	putgrass(t_window *w1);

void	*createimg(t_window *w1, char *path, int x, int y);

void	freeall(char **table, int i);

char	**inittable(t_window *w1);

char	**initmap(char *path, t_window *w1);

int	pressech(int kcode, t_window *w1);

int	initimg(t_window *w1);

#endif
