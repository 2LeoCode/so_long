#include <so_long.h>

t_walldir	process_north(t_map *map, int offset, int i, int j)
{
	const int	next_offset = offset + map->size.x;

	if (j == (map->size.x - 1) || map->data[offset + j + 1] == '1')
	{
		if (i == (map->size.y - 1) || map->data[next_offset + j] == '1')
		{
			if (!j || map->data[offset + j - 1] == '1')
				return (all);
			return (north_east_south);
		}
		if (!j || map->data[offset + j - 1] == '1')
			return (north_east_west);
		return (north_east);
	}
	if (i == (map->size.y - 1) || map->data[next_offset + j] == '1')
	{
		if (!j || map->data[offset + j - 1] == '1')
			return (north_south_west);
		return (north_south);
	}
	if (!j || map->data[offset + j - 1] == '1')
		return (north_west);
	return (north);
}

t_walldir	process_east(t_map *map, int offset, int i, int j)
{
	const int	next_offset = offset + map->size.x;

	if (i == map->size.y - 1 || map->data[next_offset + j] == '1')
	{
		if (!j || map->data[offset + j - 1] == '1')
			return (east_south_west);
		return (east_south);
	}
	if (!j || map->data[offset + j - 1] == '1')
		return (east_west);
	return (east);
}

int	get_wall_direction(t_map *map, int offset, int i, int j)
{
	t_walldir	wall_direction;
	t_wall		*wall_ptr;
	const int	prev_offset = offset - map->size.x;
	const int	next_offset = offset + map->size.x;

	wall_direction = none;
	if (!i || map->data[prev_offset + j] == '1')
		wall_direction = process_north(map, offset, i, j);
	else if (j == map->size.x - 1 || map->data[offset + j + 1] == '1')
		wall_direction = process_east(map, offset, i, j);
	else if (i == map->size.y - 1 || map->data[next_offset + j] == '1')
	{
		if (!j || map->data[offset + j - 1] == '1')
			wall_direction = south_west;
		else
			wall_direction = south;
	}
	else if (!j || map->data[offset + j - 1] == '1')
		wall_direction = west;
	wall_ptr = make_wall(j, i, wall_direction);
	if (!wall_ptr || lst_push_back(map->walls, wall_ptr, free))
		return (-1);
	return (0);
}
