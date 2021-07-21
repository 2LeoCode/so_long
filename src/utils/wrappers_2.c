#include <so_long.h>

void	*mlx_xpm_file_to_image_wrapper(void *data)
{
	static void	*key;
	void		*img_ptr;
	t_xpmwrap	*xpm_wrapper;

	img_ptr = NULL;
	if (!key)
		key = data;
	else
	{
		xpm_wrapper = (t_xpmwrap *)data;
		img_ptr = mlx_xpm_file_to_image(key,
				xpm_wrapper->filename,
				xpm_wrapper->w_ptr,
				xpm_wrapper->h_ptr);
	}
	return (img_ptr);
}

void	*lst_new_wrapper(void *dummy)
{
	(void)dummy;
	return (lst_new());
}

int	render_map_wrapper(void *map)
{
	render_map(map);
	put_main_img_to_window();
	return (0);
}
