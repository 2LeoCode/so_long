#include <so_long.h>

int	push_vec2(t_list *lst, int x, int y)
{
	t_vec2	*vec_ptr;

	vec_ptr = make_vec2(x, y);
	if (!vec_ptr || lst_push_back(lst, vec_ptr, free))
		return (-1);
	return (0);
}

bool	is_vertical_wall(const char *s, size_t len)
{
	return (*s == '1' && s[len - 1] == '1');
}

bool	is_horizontal_wall(const char *s, size_t len)
{
	while (--len && s[len] == '1')
		continue ;
	return (!len);
}

bool	check_file(const char *path)
{
	const char	*ptr;
	int			fd;

	ptr = path + ft_strlen(path) - 4;
	if (ptr < path || ft_strcmp(ptr, ".ber"))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

t_list	*get_file_content(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	t_list		*lines;
	char		*cur_line;
	int			i;

	if (fd == -1 || lst_init(&lines))
		return (NULL);
	i = 1;
	while (i)
	{
		i = get_next_line(fd, &cur_line);
		if (!ft_strisspace(cur_line))
		{
			if (lst_push_back(lines, cur_line, free))
			{
				close(fd);
				return (NULL);
			}
		}
		else
			free(cur_line);
	}
	close(fd);
	return (lines);
}
