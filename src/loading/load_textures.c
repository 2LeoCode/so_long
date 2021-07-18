#include <so_long.h>

int	load_textures(t_map *map)
{
	unsigned int	i;
	const char		*filenames[] = {
		"data/char.xpm",
		"data/endlvl.xpm",
		"data/gem.xpm",
		"data/wall.xpm",
		"data/water.xpm"
	};

	i = -1;
	while (++i < TEXTURE_CNT)
	{
		if (gb_construct_and_push(&map->tileset[i],
				init_image_from_xpm,
				(void *)filenames[i],
				free))
			return (-1);
	}
	return (0);
}
