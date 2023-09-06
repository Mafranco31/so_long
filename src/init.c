#include "../so_long.h"

static char	**maketable(t_data *w1, char *path, int i)
{
	int	fd;
	char	**table;
	char	*buf;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = get_next_line(fd);
	w1->lenght = ft_strlen(buf) - 1;
	line = NULL;
	while (buf)
	{
		i++;
		line = ft_strjoin(line, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	table = ft_split(line, '\n');
	close(fd);
	w1->width = i;
	return (table);
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

void	initdata(t_data *w1, char *path)
{
	w1->table = maketable(w1, path, 0);
	printf("%s\n%s\n%s\n%s\n%s\n%s\n", w1->table[0], w1->table[1], w1->table[2], w1->table[3], w1->table[4], w1->table[5]); 
	w1->mlx = mlx_init();
	w1->win = mlx_new_window(w1->mlx, (w1->lenght * 45), (w1->width * 45), "./so_long");
	makeimg(w1);
}
