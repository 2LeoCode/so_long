#include <so_long.h>

void	*mlx_new_window_wrapper(void *data)
{
	static void	*key;
	t_winwrap	*window_wrapper;
	void		*win_ptr;

	win_ptr = NULL;
	if (!key)
		key = data;
	else
	{
		window_wrapper = (t_winwrap *)data;
		win_ptr = mlx_new_window(key,
				window_wrapper->size.x,
				window_wrapper->size.y,
				window_wrapper->title);
	}
	return (win_ptr);
}

void	mlx_destroy_window_wrapper(void *data)
{
	static void	*key;

	if (!key)
		key = data;
	else
		mlx_destroy_window(key, data);
}

void	*mlx_new_image_wrapper(void *data)
{
	static void	*key;
	t_vec2		*image_size;
	void		*img_ptr;

	img_ptr = NULL;
	if (!key)
		key = data;
	else
	{
		image_size = (t_vec2 *)data;
		img_ptr = mlx_new_image(key,
				image_size->x,
				image_size->y);
	}
	return (img_ptr);
}

void	mlx_destroy_image_wrapper(void *data)
{
	static void	*key;

	if (!key)
		key = data;
	else
		mlx_destroy_image(key, data);
}

void	exit_wrapper(int ret)
{
	gb_clear();
	ft_putchar('\n');
	exit(ret);
}
