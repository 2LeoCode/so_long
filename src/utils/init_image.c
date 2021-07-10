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

void	*init_image_from_xpm(void *param)
{
	t_img		*new_img;
	int			x;
	int			y;
	t_xpmwrap	data;

	data.h_ptr = &y;
	data.w_ptr = &x;
	data.filename = param;
	new_img = malloc(sizeof(t_img));
	if (!new_img)
		return (NULL);
	if (gb_construct_and_push(&new_img->img_ptr, mlx_xpm_file_to_image_wrapper,
			&data, mlx_destroy_image_wrapper))
	{
		free(new_img);
		return (NULL);
	}
	new_img->data = (int *)mlx_get_data_addr(new_img->img_ptr, &new_img->bpp,
		&new_img->size_line, &new_img->endian);
	new_img->total_size = x * y;
	new_img->size.x = x;
	new_img->size.y = y;
	return (new_img);
}
