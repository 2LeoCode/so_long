#include <so_long.h>

void	put_tile(t_img *img, t_vec2 dstpos, int src_x, t_img *texture)
{
	t_vec2			ind;
	int				offset;
	int				texture_offset;
	const t_vec2	beg = {dstpos.x * TILE_SIZE, dstpos.y * TILE_SIZE};
	t_vec2			text_ind;

	ind.y = -1;
	while (++ind.y < TILE_SIZE)
	{
		ind.x = -1;
		text_ind.y = ind.y * (float)TEXT_TILE_SIZE / TILE_SIZE;
		offset = (ind.y + beg.y) * img->size_line / (img->bpp / 8);
		texture_offset = text_ind.y * texture->size_line / (texture->bpp / 8);
		while (++ind.x < TILE_SIZE)
		{
			text_ind.x = ind.x * (float)TEXT_TILE_SIZE / TILE_SIZE;
			if (texture->data[texture_offset + src_x * TEXT_TILE_SIZE
				+ text_ind.x] & 0x00ffffff)
				img->data[offset + ind.x + beg.x] =
					texture->data[texture_offset + src_x * TEXT_TILE_SIZE
					+ text_ind.x];
		}
	}
}
