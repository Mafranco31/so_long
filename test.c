#include "so_long.h"

int	main(int argc, char **argv)
{
	int fd;
	char	**table;
	char	*buf;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	buf = get_next_line(fd);
	line = NULL;
	while (buf)
	{
		line = ft_strjoin(line, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	table = ft_split(line, '\n');
	printf("%s\n\n%s\n%s\n", line, table[0], table[1]);
	return (0);
}
