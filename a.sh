gcc src/so_long.c src/checkmap.c src/key.c src/init.c src/createmap.c -Wall -Werror -Wextra -L/usr/X11 -lmlx -lXext -lX11 -L./libft -lft -L./ftprintf -lftprintf
./a.out bermaps/map1.ber
rm a.out
