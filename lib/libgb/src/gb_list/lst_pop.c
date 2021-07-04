#include <garbage.h>

void	gblst_pop(t_gblst **lst_ptr)
{
	t_gblst	*tmp;

	tmp = *lst_ptr;
	if (!tmp)
		return ;
	*lst_ptr = tmp->next;
	(*tmp->destructor)(tmp->data);
	free(tmp);
}
