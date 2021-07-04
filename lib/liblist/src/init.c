#include <list.h>

int	lst_init(t_list **lst_addr)
{
	*lst_addr = lst_new();
	if (!*lst_addr)
		return (-1);
	return (0);
}
