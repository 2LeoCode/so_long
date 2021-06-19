#include <exception.h>
#include <so_long.h>

void	kek(void)
{
	write(1, "kek\n", 4);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	*map;
	//int		errcode;

	if (argc != 2)
		return (exception(invalid_arguments));
	mlx.key = mlx_init();
	if (!mlx.key)
		return (exception(bad_alloc));
	map = get_map(argv[1]);
	if (!map)
	{
		if (errno == ENOMEM)
			return (exception(bad_alloc));
		return (exception(invalid_map));
	}
	mlx.win = mlx_new_window(mlx.key, map->size.x * TILE_SIZE, map->size.y * TILE_SIZE, "so_long");
	if (!mlx.win)
		return (exception(bad_alloc));
	mlx.main_img = init_image(mlx.key, map->size.x * TILE_SIZE, map->size.y * TILE_SIZE);
	if (!mlx.main_img.img_ptr)
		return (exception(bad_alloc));
	render_map(map, &mlx.main_img);
	mlx_put_image_to_window(mlx.key, mlx.win, mlx.main_img.img_ptr, 0, 0);
	mlx_loop(mlx.key);
	//errcode = so_long(mlx, map);
	clear_mlx(&mlx);
	free(map);
	/*if (errcode)
	{
		if (errno == ENOMEM)
			return (exception(bad_alloc));
		return (exception(runtime_error));
	}*/
	return (0);
}
