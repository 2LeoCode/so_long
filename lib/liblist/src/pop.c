#include <list.h>

void	lst_pop_front(t_list *sentinel)
{
	t_list	*tmp;

	if (sentinel->next == sentinel)
		return ;
	tmp = sentinel->next;
	tmp->next->prev = sentinel;
	sentinel->next = tmp->next;
	if (tmp->destructor)
		(*tmp->destructor)(tmp->data);
	free(tmp);
	--*sentinel->size;
}

void	lst_pop_back(t_list *sentinel)
{
	t_list	*tmp;

	if (sentinel->prev == sentinel)
		return ;
	tmp = sentinel->prev;
	tmp->prev->next = sentinel;
	sentinel->prev = tmp->prev;
	if (tmp->destructor)
		(*tmp->destructor)(tmp->data);
	free(tmp);
	--*sentinel->size;
}

void	lst_pop(t_list *node)
{
	if (node->data)
	{
		--*node->size;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (node->destructor)
			(*node->destructor)(node->data);
		free(node);
	}
}

int	lst_pop_if(t_list *sentinel, void *dataref, t_cmpf cmp_fun)
{
	t_list	*it;
	int		cnt;

	it = sentinel->next;
	cnt = 0;
	while (it != sentinel)
	{
		it = it->next;
		if (!(*cmp_fun)(it->prev->data, dataref))
		{
			lst_pop(it->prev);
			cnt++;
		}
	}
	return (cnt);
}
