/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:42:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/18 16:55:58 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception.h>
#include <so_long.h>
#include <mlx.h>

static int	destroy_handler(void *dummy)
{
	(void)dummy;
	exit_wrapper(EXIT_SUCCESS);
	return (-1);
}

int	init_map_and_mlx(t_mlx *mlx, t_map **map, char *map_path)
{
	if (gb_construct_and_push(&mlx->key, mlx_init, NULL,
		mlx_destroy_display_wrapper))
		return (exception(bad_alloc));
	init_wrappers(mlx->key);
	if (get_map(map, map_path) || load_textures(*map))
	{
		if (errno == ENOMEM)
			return (exception(bad_alloc));
		else
			return (exception(invalid_map));
	}
	if (gb_construct_and_push(&mlx->win, mlx_new_window_wrapper,
			(t_winwrap []){{(t_vec2){(*map)->size.x * TILE_SIZE,
				(*map)->size.y * TILE_SIZE}, "so_long"}},
				mlx_destroy_window_wrapper))
		return (exception(bad_alloc));
	if (gb_construct_and_push(&mlx->main_img, init_image, (t_vec2 []){{
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
	if (init_map_and_mlx(&mlx, &map, argv[1]))
		return (-1);
	init_renderer(mlx.main_img);
	load_main_img_to_window(mlx.key, mlx.win, mlx.main_img);
	mlx_key_hook(mlx.win, key_hook, map);
	mlx_hook(mlx.win, VisibilityNotify, VisibilityChangeMask,
		render_map_wrapper, map);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask,
		destroy_handler, NULL);
	mlx_loop(mlx.key);
	return (0);
}
