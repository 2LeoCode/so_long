#include <exception.h>
#include <so_long.h>

void	kek(void)
{
	write(1, "kek\n", 4);
}

static int	destroy_handler(void *dummy)
{
	(void)dummy;
	exit_wrapper(EXIT_SUCCESS);
	return (-1);
}

int	init_map_and_mlx(t_mlx *mlx_ptr, t_map **map_ptr)
{
	mlx->key = mlx_init();
	if (!mlx->key)
		return (exception(bad_alloc));
	init_wrappers(mlx->key);
	if (get_map(map, argv[1]) || load_textures(*map))
	{
		if (errno == ENOMEM)
			return (exception(bad_alloc));
		else
			return (exception(invalid_map));
	}
	if (gb_construct_and_push(&mlx->win, mlx_new_window_wrapper,
			(t_winwrap []){{(t_vec2){(*map)->size.x * TILE_SIZE,
			(*map)->size.y * TILE_SIZE}, "so_long"}}, mlx_destroy_window_wrapper))
		return (exception(bad_alloc));
	if (gb_construct_and_push(&mlx.main_img, init_image, (t_vec2 []){{
		(*map)->size.x * TILE_SIZE, (*map)->size.y * TILE_SIZE}}, free))
		return (exception(bad_alloc));
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	*map;

	if (argc != 2)
		return (exception(invalid_arguments));
	if (init_map_and_mlx(&mlx, &map))
		return (-1);
	init_renderer(mlx.main_img);
	render_map(map);
	mlx_key_hook(mlx.win, key_hook, (void *)map);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, destroy_handler, NULL);
	load_main_img_to_window(mlx.key, mlx.win, mlx.main_img);
	put_main_img_to_window();
	mlx_loop(mlx.key);
	return (0);
}
