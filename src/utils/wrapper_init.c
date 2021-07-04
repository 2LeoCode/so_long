#include <so_long.h>

void	init_wrappers(void *key)
{
	mlx_new_image_wrapper(key);
	mlx_new_window_wrapper(key);
	mlx_destroy_window_wrapper(key);
	mlx_destroy_image_wrapper(key);
}
