#include <so_long.h>

static void	put_tile(t_img *img, t_vec2 dstpos, int src_x, t_img *texture)
{
	int	i;
	int	offset;
	int	texture_offset;
	int	j;
	const int	begX = dstpos.x * TILE_SIZE;
	const int	begY = dstpos.y * TILE_SIZE;

	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		offset = (i + begY) * img->size_line / (img->bpp / 8);
		texture_offset = i * texture->size_line / (texture->bpp / 8);
		while (++j < TILE_SIZE)
			if (texture->data[texture_offset + src_x * TILE_SIZE + j] & 0x00ffffff)
				img->data[offset + j + begX] = texture->data[texture_offset + src_x * TILE_SIZE + j];
	}
}

void	renderer(t_map *map, t_img *img_init)
{
	static t_img		*img = NULL;
	t_list				*it;
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
		i = -1;
		printf("dir: %d\n", map->player_direction);
		put_tile(img, map->player_pos, map->player_direction, map->tileset[character]);
		put_tile(img, map->exit_pos, 0, map->tileset[end_level]);
		it = map->walls->next;
		while (it != map->walls)
		{
			put_tile(img, (t_vec2){((t_wall *)it->data)->x, ((t_wall *)it->data)->y}, ((t_wall *)it->data)->orientation, map->tileset[wall]);
			it = it->next;
		}
		it = map->collect_pos->next;
		while (it != map->collect_pos)
		{
			put_tile(img, *(t_vec2 *)it->data, 0, map->tileset[gem]);
			it = it->next;
		}
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
