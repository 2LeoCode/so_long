#include <so_long.h>

static void	*map_failure(t_map *map)
{
	free(map);
	return (NULL);
}

static bool	is_vertical_wall(const char *s, size_t len)
{
	return (*s == '1' && s[len - 1] == '1');
}

static bool	is_horizontal_wall(const char *s, size_t len)
{
	while (--len && s[len] == '1')
		continue ;
	return (!len);
}

static int	check_file(char *path)
{
	char	*ptr;
	int		fd;

	ptr = path + ft_strlen(path) - 4;
	if (ptr < path || ft_strcmp(ptr, ".ber"))
		return (1);
	fd = open(path, O_RDONLY);
	return (0)
}

t_map	*get_map(char *path)
{
	char	**file_content;
	t_map	*map;
	int		fd;
	t_vec2	map_size;

	if (check_map(path, &map_size.x, &map_size.y))
		return (-1);
	map = malloc(sizeof(t_map) + sizeof(char) * (map_size.x * map_size.y));
	if (!map)
		return (-1);
	
}
