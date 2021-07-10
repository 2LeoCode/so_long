#include <so_long.h>

t_wall	*make_wall(int x, int y, t_walldir orientation)
{
	t_wall	*new_wall;

	new_wall = malloc(sizeof(t_wall));
	if (new_wall)
	{
		new_wall->x = x;
		new_wall->y = y;
		new_wall->orientation = orientation;
	}
	return (new_wall);
}
