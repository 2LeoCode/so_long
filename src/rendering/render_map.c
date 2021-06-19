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
	printf("x %d, y %d\n", x, y);
	int endY = (y + 1) * TILE_SIZE;
	int endX = (x + 1) * TILE_SIZE;
	for (int i = y * TILE_SIZE; i < endY; i++)
		for (int j = x * TILE_SIZE; j < endX; j++) {
			img->data[i * img->size.x + j] = color;
		}
}

void	render_map(t_map *map, t_img *img)
{
	(void )map;
	static int			color[127];
	static bool			init = false;
	//const static int	coef = TILE_SIZE * TILE_SIZE;
	//int				i;
	//int				j;
	//int				map_y;

	if (!init)
	{
		init_characters(color);
		init = true;
	}
	printf("%d, %d\n%d, %d\n", map->size.x, map->size.y, img->size.x, img->size.y);
	for (int i = 0; i < TILE_SIZE; i++)
		for (int j = 0; j < TILE_SIZE; j++)
			img->data[i * img->size.x / 4 + j] = 0x00ffffff;
	/*for (int i = 0; i < map->size.y; i++)
	{
		for (int j = 0; j < map->size.x; j++)
		{
			put_tile(img, j, i, color[(unsigned)map->data[i * map->size.x + j]]);
		}
	}*/
}
