#include <so_long.h>

void	*init_image(void *param)
{
	t_img	*new_img;

	new_img = malloc(sizeof(t_img));
	if (!new_img)
		return (NULL);
	if (gb_construct_and_push(&new_img->img_ptr, mlx_new_image_wrapper, param,
			mlx_destroy_image_wrapper))
	{
		free(new_img);
		return (NULL);
	}
	new_img->data = (int *)mlx_get_data_addr(new_img->img_ptr, &new_img->bpp,
					&new_img->size_line, &new_img->endian);
	new_img->total_size = ((t_vec2 *)param)->x * ((t_vec2 *)param)->y;
	new_img->size.x = ((t_vec2 *)param)->x;
	new_img->size.y = ((t_vec2 *)param)->y;
	return (new_img);
}
