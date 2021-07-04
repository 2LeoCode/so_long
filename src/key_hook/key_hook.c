#include <so_long.h>

int	update_map(int keycode, t_map *map)
{
	(void)keycode;
	(void)map;
	return (0);
}

void	print_move(int keycode)
{
	(void)keycode;
}

int	key_hook(int keycode, void *param)
{
	static int	mv_cnt = 0;
	int			status;

	if (keycode == _KEY_ESC)
		exit_wrapper(EXIT_SUCCESS);
	status = update_map(keycode, (t_map *)param);
	if (!status)
		return (1);
	mv_cnt++;
	ft_putnbr(mv_cnt);
	if (status == 1)
		mv_cnt = 0;
	render_map((t_map *)param);
	put_main_img_to_window();
	return (0);
}
