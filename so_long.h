#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include "include/libft.h"
# include <fcntl.h>

typedef struct	s_img
{
	char	*pathdog;
	char	*pathgrass;
	char	*pathkennel;
	char	*pathhotdog;
	char	*pathfence;
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

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	int	lenght;
	int	width;
	t_img	img;
	char	**table;
}		t_data;

void	initdata(t_data *w1, char *path);

void	initmap(t_data *w1);

//void	putimg(t_data *w1, char c, int x, int y);

int	presskey(int kcode, t_data *w1);

#endif
