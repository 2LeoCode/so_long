#include <list.h>

int	lst_failure(t_list *sentinel, void *data, t_destructor destructor)
{
	(*destructor)(data);
	lst_destroy(sentinel);
	return (-1);
}
