#include <list.h>

t_list	*lst_find(t_list *sentinel, void *dataref, t_cmpf cmp_fun)
{
	t_list	*it;

	it = sentinel->next;
	while (it != sentinel && (*cmp_fun)(it->data, dataref))
		it = it->next;
	return ((t_list *)((ptrdiff_t)it * (it != sentinel)));
}

t_list	*lst_rfind(t_list *sentinel, void *dataref, t_cmpf cmp_fun)
{
	t_list	*it;

	it = sentinel->prev;
	while (it != sentinel && (*cmp_fun)(it->data, dataref))
		it = it->prev;
	return ((t_list *)((ptrdiff_t)it * (it != sentinel)));
}
