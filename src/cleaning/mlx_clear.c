#include <so_long.h>

void	clear_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->key, mlx->win);
	mlx_destroy_image(mlx->key, mlx->main_img->img_ptr);
}
