#include <list.h>

void	lst_clear(t_list *sentinel)
{
	t_list			*it;
	t_list			*tmp;

	it = sentinel->next;
	while (it != sentinel)
	{
		tmp = it;
		it = it->next;
		if (tmp->destructor)
			(*tmp->destructor)(tmp->data);
		free(tmp);
	}
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
	*sentinel->size = 0;
}

void	lst_safe_clear(t_list *sentinel)
{
	t_list			*it;
	t_list			*tmp;

	it = sentinel->next;
	while (it != sentinel)
	{
		tmp = it;
		it = it->next;
		free(tmp);
	}
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
	*sentinel->size = 0;
}
