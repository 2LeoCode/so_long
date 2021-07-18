#include <so_long.h>

void	put_tile(t_img *img, t_vec2 dstpos, int src_x, t_img *texture)
{
	t_vec2		ind;
	int			offset;
	int			texture_offset;
	const int	begX = dstpos.x * TILE_SIZE;
	const int	begY = dstpos.y * TILE_SIZE;

	ind.y = -1;
	while (++ind.y < TILE_SIZE)
	{
		ind.x = -1;
		offset = (ind.y + begY) * img->size_line / (img->bpp / 8);
		texture_offset = ind.y * texture->size_line / (texture->bpp / 8);
		while (++ind.x < TILE_SIZE)
			if (texture->data[texture_offset + src_x * TILE_SIZE + ind.x]
				& 0x00ffffff)
				img->data[offset + ind.x + begX]
					= texture->data[texture_offset + src_x * TILE_SIZE + ind.x];
	}
}
