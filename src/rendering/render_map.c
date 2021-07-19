#include <so_long.h>

static void	put_walls(t_map *map, t_img *img)
{
	const t_list	*it = map->walls->next;

	while (it != map->walls)
	{
		put_tile(img,
			(t_vec2){((t_wall *)it->data)->x, ((t_wall *)it->data)->y},
			((t_wall *)it->data)->orientation,
			map->tileset[wall]);
		it = it->next;
	}
}

static void	put_tile_list(t_map *map, enum e_texture index, t_img *img)
{
	const t_list	*it;
	const t_list	*end = map->collect_pos;

	if (index == end_level)
		end = map->exit_pos;
	else if (index != gem)
		return ;
	it = end->next;
	while (it != end)
	{
		put_tile(img, *(t_vec2 *)it->data, 0, map->tileset[index]);
		it = it->next;
	}
}

static void	renderer(t_map *map, t_img *img_init)
{
	static t_img		*img = NULL;
	int					i;
	int					j;

	(void)map;
	if (img_init)
		img = img_init;
	else
	{
		i = -1;
		while (++i < map->size.y)
		{
			j = -1;
			while (++j < map->size.x)
				put_tile(img, (t_vec2){j, i}, 0, map->tileset[water]);
		}
		put_tile(img, map->player_pos, map->player_direction,
			map->tileset[character]);
		put_walls(map, img);
		put_tile_list(map, gem, img);
		put_tile_list(map, end_level, img);
	}
}

void	render_map(t_map *map)
{
	renderer(map, NULL);
}

void	init_renderer(t_img *img_init)
{
	renderer(NULL, img_init);
}
