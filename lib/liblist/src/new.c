#include <list.h>

t_list	*lst_new(void)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->size = (size_t *)malloc(sizeof(size_t));
	if (!new_lst->size)
	{
		free(new_lst);
		return (NULL);
	}
	*new_lst->size = 0;
	new_lst->data = NULL;
	new_lst->destructor = NULL;
	new_lst->next = new_lst;
	new_lst->prev = new_lst;
	return (new_lst);
}
