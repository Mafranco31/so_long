#include "../include/so_long.h"

void	freeall(char **table, int i)
{
	while (table[i])
	{
		free(table[i]);
		i--;
	}	
	free(table);	
}

static char	**maketable(t_data *w1, int i, int fd)
{
	char	**table;
	char	*buf;
	char	*line;

	buf = get_next_line(fd);
	w1->lenght = ft_strlen(buf) - 1;
	line = NULL;
	while (buf)
	{
		i++;
		line = ft_strjoin(line, buf);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
		free(buf);
		buf = get_next_line(fd);
	}
	table = ft_split(line, '\n');
	w1->width = i;
	w1->count = 0;
	w1->moove = 0;
	return (table);
}

static int	checkimg(t_data *w1)
{
	t_img	*ptr;

	ptr = &w1->img;
	if (!ptr->dog || !ptr->grass || !ptr->kennel || !ptr->hotdog || !ptr->fence)
		return (1);
	return (0);
}

void	makeimg(t_data *w1)
{
	w1->img.h = 45;
	w1->img.w = 45;
	w1->img.pathdog = "./xpmfiles/dog.xpm";
	w1->img.pathgrass = "./xpmfiles/grass.xpm";
	w1->img.pathkennel = "./xpmfiles/kennel.xpm";
	w1->img.pathhotdog = "./xpmfiles/hotdog.xpm";
	w1->img.pathfence = "./xpmfiles/fence.xpm";
	w1->img.dog = mlx_xpm_file_to_image(w1->mlx, w1->img.pathdog, &(w1->img.h), &(w1->img.w));
	w1->img.grass = mlx_xpm_file_to_image(w1->mlx, w1->img.pathgrass, &(w1->img.h), &(w1->img.w));
	w1->img.kennel = mlx_xpm_file_to_image(w1->mlx, w1->img.pathkennel, &(w1->img.h), &(w1->img.w));
	w1->img.hotdog = mlx_xpm_file_to_image(w1->mlx, w1->img.pathhotdog, &(w1->img.h), &(w1->img.w));
	w1->img.fence = mlx_xpm_file_to_image(w1->mlx, w1->img.pathfence, &(w1->img.h), &(w1->img.w));
}

int	initdata(t_data *w1)
{
	int	fd;

	fd = open(w1->path, O_RDONLY);
	if (fd == -1)
		return (end(w1, "READ OF MAP FAILED", 1));
	w1->table = maketable(w1, 0, fd);
	close(fd);
	if (w1->table == NULL)
		return (end(w1, "MALLOC FAILED", 1));
	w1->mlx = mlx_init();
	w1->win = mlx_new_window(w1->mlx, (w1->lenght * 45), (w1->width * 45), "./so_long");
	if (w1->win == NULL)
		return (end(w1, "CREATING WINDOW FAILED", 1));
	makeimg(w1);
	if (checkimg(w1) == 1)
		return (end(w1, "CREATING IMAGE FAILED", 1));
	return (0);
}
