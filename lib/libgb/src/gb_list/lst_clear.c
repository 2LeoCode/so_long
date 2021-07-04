#include <garbage.h>

void	gblst_clear(t_gblst **lst_ptr)
{
	t_gblst	*head;

	while (*lst_ptr)
	{
		head = (*lst_ptr)->next;
		(*(*lst_ptr)->destructor)((*lst_ptr)->data);
		free(*lst_ptr);
		*lst_ptr = head;
	}
}
