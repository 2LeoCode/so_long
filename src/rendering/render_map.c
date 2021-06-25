#include <so_long.h>

static void	init_characters(int c[127])
{
	c['0'] = make_color(255, 255, 255);
	c['1'] = make_color(0, 0, 0);
	c['C'] = make_color(0, 0, 255);
	c['P'] = make_color(255, 0, 0);
	c['E'] = make_color(0, 255, 0);
}

void	put_tile(t_img *img, int x, int y, int color)
{
	int	i;
	int	i2;
	int	j;
	int	endX;
	int	endY;

	i = y - 1;
	endX = x + TILE_SIZE;
	endY = y + TILE_SIZE;
	while (++i < endY)
	{
		j = x - 1;
		i2 = i * img->size_line / (img->bpp / 8);
		while (++j < endX)
			img->data[i2 + j] = color;
	}
}

void	render_map(t_map *map, t_img *img)
{
	static int			color[127];
	static bool			init = false;
	int					i;
	int					y;
	int					j;

	(void)map;
	if (!init)
	{
		init_characters(color);
		init = true;
	}
	i = -1;
	while (++i < map->size.y)
	{
		j = -1;
		y = i * map->size.x;
		while (++j < map->size.x)
			put_tile(img, j * TILE_SIZE, i * TILE_SIZE, color[(unsigned int)map->data[y + j]]);
	}
}
