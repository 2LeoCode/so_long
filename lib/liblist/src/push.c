#include <list.h>

int	lst_push_front(t_list *sentinel, void *data, t_destructor destructor)
{
	t_list	*new_node;

	if (!data)
		return (0);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (lst_failure(sentinel, data, destructor));
	new_node->data = data;
	new_node->destructor = destructor;
	new_node->size = sentinel->size;
	new_node->prev = sentinel;
	new_node->next = sentinel->next;
	sentinel->next->prev = new_node;
	sentinel->next = new_node;
	++*sentinel->size;
	return (0);
}

int	lst_push_back(t_list *sentinel, void *data, t_destructor destructor)
{
	t_list	*new_node;

	if (!data)
		return (0);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (lst_failure(sentinel, data, destructor));
	new_node->data = data;
	new_node->destructor = destructor;
	new_node->size = sentinel->size;
	new_node->prev = sentinel->prev;
	new_node->next = sentinel;
	sentinel->prev->next = new_node;
	sentinel->prev = new_node;
	++*sentinel->size;
	return (0);
}
