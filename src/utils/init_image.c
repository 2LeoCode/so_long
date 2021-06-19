#include <so_long.h>

t_img	init_image(void *mlx_key, int x, int y)
{
	t_img	new_img;

	new_img.img_ptr = mlx_new_image(mlx_key, x, y);
	if (new_img.img_ptr)
		new_img.data = (int *)mlx_get_data_addr(new_img.img_ptr, &new_img.bpp,
			&new_img.size_line, &new_img.endian);
	new_img.total_size = x * y;
	new_img.size.x = x;
	new_img.size.y = y;
	return (new_img);
}
