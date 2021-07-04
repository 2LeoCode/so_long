#include <so_long.h>

static void	img_loader(void *key, void *win, t_img *main_img)
{
	static void		*saved_key;
	static void		*saved_win;
	static t_img	*saved_img;

	if (key && win && main_img)
	{
		saved_key = key;
		saved_win = win;
		saved_img = main_img;
	}
	else
		mlx_put_image_to_window(saved_key, saved_win, saved_img->img_ptr, 0, 0);
}

void	load_main_img_to_window(void *key, void *win, t_img *main_img)
{
	img_loader(key, win, main_img);
}

void	put_main_img_to_window(void)
{
	img_loader(NULL, NULL, NULL);
}
